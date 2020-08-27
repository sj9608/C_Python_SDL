# %%

import socket

# TCP server 객체
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_socket.bind(("127.0.0.1", 8282))
server_socket.listen(5)

while True:
    print('wait connect')
    client_socket, addr = server_socket.accept()
    print(f'connected {addr}')

    print('wait data')
    # client_socket.recv(1024)
    data = client_socket.recv(1024)

    print(f'received : {addr} : {data.decode()}')

    client_socket.sendall('bye'.encode())
    client_socket.close()
# %%
