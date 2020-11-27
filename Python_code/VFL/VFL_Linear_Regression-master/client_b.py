import socket, pickle
from phe import paillier
from sklearn import datasets
import numpy as np
from sklearn.metrics import r2_score, mean_squared_error


HOST_A, HOST_B, HOST_C = 'localhost', 'localhost', 'localhost'
PORT_A, PORT_B, PORT_C = 10001, 10002, 10000
GLOBAL_EPOCHS = 10000
PARTITION_IDX = 5
LAMBDA = 0.01
LEARNING_RATE = 0.01


# get public key from aggregator_c
sock_key = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock_key.connect((HOST_C, PORT_C))
sock_key.send(pickle.dumps({'name': 'public_key', 'data': None}))
public_key = pickle.loads(sock_key.recv(4096))
print('public key:', public_key)
sock_key.close()


# loading datasets
diabetes_X, diabetes_y = datasets.load_diabetes(return_X_y=True)
trainset = diabetes_X[:-20, PARTITION_IDX:]
testset = diabetes_X[-20:, PARTITION_IDX:]
train_y = diabetes_y[:-20]
test_y = diabetes_y[-20:]


NUM_SAMPLES = trainset.shape[0]
MASK_B = np.random.random(diabetes_X.shape[1] - PARTITION_IDX)
MASK_B_encrypted = [public_key.encrypt(value) for value in MASK_B]


# initialize training parameters
theta_b = np.random.normal(0, 1.0, diabetes_X.shape[1] - PARTITION_IDX)
print('theta B:', theta_b)
bias = np.random.random()


# estabilish B's itself server socket for receiving `U_A`& 'L_A' from A
sock_server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock_server.bind((HOST_B, PORT_B))
sock_server.listen(2)




for epoch in range(GLOBAL_EPOCHS):
    # waiting for A's conncetion
    conn, addr = sock_server.accept()
    print('conncetion established...')
    # ===RECEIVING===
    data = []
    while True:
        packet = conn.recv(1024)
        if not packet: break
        data.append(packet)
    loss_a_encrypted, u_a_encrypted = pickle.loads(b''.join(data))
    # u_a_numpy = np.array(u_a_encrypted)
    print('loss A and U_A recieved...')
    conn.close()


    loss_b_encrypted = \
        public_key.encrypt(float((1. / NUM_SAMPLES) * sum((trainset.dot(theta_b.T) + bias - train_y) ** 2) \
            + (LAMBDA / 2.) * sum(theta_b ** 2)))
    u_b_minus_y = (trainset.dot(theta_b.T) + bias - train_y).tolist()
    loss_ab_encrypted = public_key.encrypt(0.0)
    for idx in range(len(u_b_minus_y)):
        loss_ab_encrypted += u_b_minus_y[idx] * u_a_encrypted[idx]
    loss_ab_encrypted *= 2. / NUM_SAMPLES

    loss_total = loss_a_encrypted + loss_b_encrypted + loss_ab_encrypted
    print('total loss finished...')

    d_i_encrypted = []
    for idx in range(len(u_b_minus_y)):
        d_i_encrypted.append(public_key.encrypt(u_b_minus_y[idx]) + u_a_encrypted[idx])
    d_i_numpy = np.array(d_i_encrypted)
    # ===SENDING===
    sock_client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock_client.connect((HOST_A, PORT_A))
    sock_client.send(pickle.dumps(d_i_encrypted))
    sock_client.close()
    print('d_i sended...')

    second_term = [public_key.encrypt(LAMBDA * theta) for theta in theta_b]

    gradient_b_encrypted = (2 / NUM_SAMPLES) * \
        (d_i_numpy[:, np.newaxis] * trainset).sum(axis=0) + np.array(second_term)

    gradient_bias_encrypted = (2 / NUM_SAMPLES) * sum(d_i_numpy)

    print('gradient already computed...')

    sock_aggregator = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock_aggregator.connect((HOST_C, PORT_C))
    sock_aggregator.send(
        pickle.dumps(
            {
                'name': 'B', 
                'data': 
                    {
                        'gradient_theta': gradient_b_encrypted + np.array(MASK_B_encrypted),
                        'gradient_bias': gradient_bias_encrypted, 
                        'loss': loss_total
                    }
            }
        )
    )
    print('gradient sended...')
    recv_data = pickle.loads(sock_aggregator.recv(4096))
    theta_b = theta_b - LEARNING_RATE * (recv_data['gradient_theta'] - MASK_B)
    bias = bias - LEARNING_RATE * recv_data['gradient_bias']
    sock_aggregator.close()




# print model params
print('theta B:', theta_b)
print('bias:', bias)


## TESTING PHASE
ub = testset.dot(theta_b) + bias 
ub_encrypted = [public_key.encrypt(float(value)) for value in ub]
sock_testing = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock_testing.connect((HOST_C, PORT_C))
sock_testing.send(
    pickle.dumps(
        {'name': 'testing', 'data': ub_encrypted}
    )
)
print('testing ub sended...')

# receive preditions from C
conn, addr = sock_server.accept()
preds = pickle.loads(conn.recv(4096))
print('predictions: {}'.format(preds))
conn.close()

print('testing MSE: {}'.format(mean_squared_error(test_y, preds)))
print('r2 score: {}'.format(r2_score(test_y, preds)))


# close socket connection
sock_server.close()


