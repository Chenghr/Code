import socket
import pickle
import json
from phe import paillier


HOST = 'localhost'
PORT = 20000


# data = []
# while True:
#     tmp = s.recv(1024)
#     if not tmp: break
#     data.append(tmp)
# print('lenght of data:{}'.format(len(data)))
# data = pickle.loads(b''.join(data))
# print(len(data))

# while True:
#     data = []
#     while True:
#         tmp = s.recv(1024)
#         if not tmp: break
#         data.append(tmp)
#     packet = pickle.loads(b''.join(data))
#     print('data len:{}, packet len:{}'.format(len(data), len(packet)))

'''did not work'''  
# idx = 0
# while True:
#     data = []
#     tmp = s.recv(1024)
#     idx += 1
#     data.append(tmp)
#     if idx % 20 == 0:
#         packet = pickle.loads(b''.join(data))
#         print('data len:{}, packet len:{}'.format(len(data), len(packet)))
#         data = []

while True:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST, PORT))
    print('connect to server successfully...')

    data = []
    while True:
        packet = s.recv(1024)
        if not packet: break
        data.append(packet)
    packet = pickle.loads(b''.join(data))
    print('data len:{}, packet len:{}'.format(len(data), len(packet)))

    s.close()

    
    

    

# while True:
#     pub_key = pickle.loads(s.recv(1280)) # using pickle for serialisation
#     print(pub_key)
    

