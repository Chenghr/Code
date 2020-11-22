import socket, pickle
from phe import paillier
import numpy as np

# generating public_key & private_key pairs
public_key, private_key = paillier.generate_paillier_keypair(n_length=256)
print('public key: ', public_key)
print('private key:', private_key)

# estabilishing sockets with client_a & client_b respectively
# TODO: pack all configurations into a Config class, e.g., ServerConfig & Client_Config
# TODO: try to use StreanRequestHandler to fork a process

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
HOST, PORT = 'localhost', 10000
HOST_A, PORT_A = 'localhost', 10001
HOST_B, PORT_B = 'localhost', 10002
# TODO: if the server allows conncetion outside the local machine,
# then the HOST variable should change to 's.gethostname()'
s.bind((HOST, PORT))
s.listen(4)

GLOBAL_EPOCHS = 50

# main loop
# TODO: try to use a fork socket server to deal each conncetion seperately
epoch = 0
preds = []
client_count = 0
while True:
    conn, addr = s.accept()
    # TODO: modify the recv procedure to deal with much larger gradient
    data = pickle.loads(conn.recv(4096))
    if data['name'] == 'public_key':
        conn.send(pickle.dumps(public_key))
        conn.close() 
    elif data['name'] == 'A':
        decrypted_grads = [private_key.decrypt(value) for value in data['data']]
        conn.send(pickle.dumps(np.array(decrypted_grads)))
        conn.close()
    elif data['name'] == 'B':
        dict_data = data['data']
        decrypted_grads = [private_key.decrypt(value) for value in dict_data['gradient_theta']]
        decrypted_grads_bias = private_key.decrypt(dict_data['gradient_bias'])
        print('epoch: {}, loss: {}'\
            .format(epoch, private_key.decrypt(dict_data['loss'])))
        epoch += 1 # TODO: global epochs
        conn.send(pickle.dumps(
            {'gradient_theta': decrypted_grads, 'gradient_bias': decrypted_grads_bias}
        ))
        conn.close()
    elif data['name'] == 'testing':
        client_count += 1
        if client_count == 1: 
            preds = [private_key.decrypt(value) for value in data['data']].copy()
            conn.close()
        elif client_count == 2:
            recv_pred = [private_key.decrypt(value) for value in data['data']]
            preds = [val1 + val2 for val1, val2 in zip(preds, recv_pred)]
            conn.close()
            break
    else:
        pass


# send back to A
socket_A = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socket_A.connect((HOST_A, PORT_A))
socket_A.send(pickle.dumps(preds))
socket_A.close()
# send back to B
socket_B = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socket_B.connect((HOST_B, PORT_B))
socket_B.send(pickle.dumps(preds))
socket_B.close()

print('###SERVER FINISHED###')






