import socket, pickle
from phe import paillier
from sklearn import datasets
import numpy as np

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
print('received public key:', public_key)
sock_key.close()


# loading datasets
diabetes_X, _ = datasets.load_diabetes(return_X_y=True)
trainset = diabetes_X[:-20, 0:PARTITION_IDX]
testset = diabetes_X[-20:, 0:PARTITION_IDX]
print('trianset shape:', trainset.shape)


NUM_SAMPLES = trainset.shape[0]
MASK_A = np.random.random(PARTITION_IDX)
MASK_A_encrypted = [public_key.encrypt(value) for value in MASK_A]

# initialize training parameters
theta_a = np.random.normal(0, 1.0, PARTITION_IDX)
print('theta A:', theta_a)


sock_server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock_server.bind((HOST_A, PORT_A))
sock_server.listen(2)


for epoch in range(GLOBAL_EPOCHS):
    # estabilish a socket to connect with B
    sock_client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock_client.connect((HOST_B, PORT_B))

    # TODO: can be optimized to speed up encryption on float numbers
    loss_a_encrypted = \
        public_key.encrypt(float((1. / NUM_SAMPLES) * sum(trainset.dot(theta_a.T) ** 2) \
            + (LAMBDA / 2.) * sum(theta_a ** 2)))
    u_a_encrypted = \
        [public_key.encrypt(float(value)) for value in trainset.dot(theta_a.T)]
    print('loss A and U_A completed...')

    # ===SENDING===
    sock_client.send(pickle.dumps([loss_a_encrypted, u_a_encrypted]))
    sock_client.close()
    print('loss A and U_A sended...')

    
    # ===RECEIVING===
    conn, addf = sock_server.accept()
    data = []
    while True:
        packet = conn.recv(1024)
        if not packet: break
        data.append(packet)
    d_i_encrypted = pickle.loads(b''.join(data))
    d_i_numpy = np.array(d_i_encrypted)
    conn.close()
    print('d_i recieved...')

    second_term = [public_key.encrypt(LAMBDA * theta) for theta in theta_a]
    
    gradient_a_encrypted = (2. / NUM_SAMPLES) * \
        (d_i_numpy[:, np.newaxis] * trainset).sum(axis=0) + np.array(second_term)
    print('gradient already computed...')

    # ===SENDING===
    sock_aggregator = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock_aggregator.connect((HOST_C, PORT_C))
    sock_aggregator.send(
        pickle.dumps(
            {'name': 'A', 'data': gradient_a_encrypted + np.array(MASK_A_encrypted)}
        )
    )
    print('gradient sended...')
    # ===RECEIVING===
    gradient_decrypted = pickle.loads(sock_aggregator.recv(4096))
    theta_a = theta_a - LEARNING_RATE * (gradient_decrypted - MASK_A)
    

    sock_aggregator.close()


# print model params
print('theta A:', theta_a)

## TESTING PHASE
ua = testset.dot(theta_a)
ua_encrypted = [public_key.encrypt(float(value)) for value in ua]
sock_testing = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock_testing.connect((HOST_C, PORT_C))
sock_testing.send(
    pickle.dumps(
        {'name': 'testing', 'data': ua_encrypted}
    )
)
print('testing ua sended...')

# receive preditions from C
conn, addr = sock_server.accept()
preds = pickle.loads(conn.recv(4096))
print('predictions: {}'.format(preds))
conn.close()


# close socket connection
sock_server.close()
