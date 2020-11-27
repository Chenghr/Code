import socket
from phe import paillier
import pickle
import json
import time

pub_key, priv_key = paillier.generate_paillier_keypair(n_length=128)
print('public key:', pub_key)
print('private key:', priv_key)

HOST = 'localhost'
PORT = 20000
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen(4)
print('server starting...')



# for sending a big object
data = []
for i in range(10000):
    data.append(pub_key)

# size = conn.send(pickle.dumps(data))
# print('size: {} bytes sended...'.format(size))
# conn.sendall(pickle.dumps(data))


idx = 1
while True:
    conn, addr = s.accept()
    print('connected by:', addr)    
    # time.sleep(20)
    size = conn.send(pickle.dumps(data)) # usiprint(size) if idx == 1 else print('')
    print('idx: {}, size: {} public key sended'.format(idx, size))
    idx += 1
    # time.sleep(5)
    conn.close()
    
