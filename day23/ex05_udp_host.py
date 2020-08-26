
# TCP와 UDP이ㅡ 차이 
# UDP는 서버에서 accept 하는 부분이 없다. 하나의 차이
# 그 accept 의 개념을 우리가 만들어야함.
# 양방향에서 bind를 걸어놓고 (p2p) 포트를 열어놓고
# 포트로 전송을하면 데이터를 받는다.

# tcp는 전화를 걸고 받으면 시작
# udp는 무전의 느낌.

#%% 

import socket

# server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) TCP 통신  listen , accept가 있다.

udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP 통신 connect, disconnect의 개념이 없다. 차이는 초기화 방식 STREAM , DGRAM
udp_socket.bind(('127.0.0.1', 8284)) # 바인드는 튜플형태로 받는다.

print('bind port 8284')

#%%

_data , _rinfo = udp_socket.recvfrom(1024) # 데이터를 받는다.

# {_rinfo[0]} ip 주소 {_rinfo[1]} 포트주소
print(f'received : {_rinfo[0]} : {_rinfo[1]} : {_data.decode()}')
