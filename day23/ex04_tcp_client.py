#%%

import socket

# tcp client object / tcp 클라이언트 객체 생성

client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)


#%%


# 클라이언트는 bind와 listen 이 필요 없다.
# 바로 connect 해주면 됨 주소와, 포트를 가지고 연결 요청을 한다.
# 주소와 포트는 튜플 형태로 묶는다.
print('try to connect server ...')
client_socket.connect(("127.0.0.1", 8282))

print('connected')
# %%

print('sending message')
client_socket.sendall('안녕'.encode())
print('send message ok')
# %%

print('wait message')
data = client_socket.recv(1024)
print(f'received : {data.decode()}')

client_socket.close()
# %%
