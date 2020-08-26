#%%

# 서버 만드는 것
# 소켓은 내부 모델

import socket

# TCP server 객체
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 할당받을 ip 입력 ( 아무것도 입력하지 않으면 자동으로 잡아줌 ) (127.0.0.1)--> 내부 공개용 (내부에서 통신할 떄) 프로세스간 통신을 할 때
# 두번째 오는 번호는 port 번호
server_socket.bind(("127.0.0.1", 8282))

# 줄의 객체가 5줄 (손님 받을 인원수 라고 생각하면됨)

server_socket.listen(5) 

print('wait connect')

# 블로킹 함수 실행이 아래 함수를 만나서 멈추고 다음 사람이 접속해야 활동됨
# 함수가 클라이언트 소켓을 반환한다. 네트워크에서 데이터를 받아오기 위한 객체
client_socket,addr = server_socket.accept()
print(f'connected {addr}')

# 데이터를 받아올 단위 설정 ( 1024 단위로 받아들임) 1024 넘으면 잘라서 읽어들임

print('wait data')
# client_socket.recv(1024) 
data = client_socket.recv(1024)

print(f'received : {addr} : {data.decode()}')


# %%

# 서버에서 클라이언트 쪽으로 데이터 받기

client_socket.sendall('bye'.encode())
client_socket.close()
# %%
