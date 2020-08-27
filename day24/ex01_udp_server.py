#%%

import socket
from struct import *

udp_socket = socket.socket(
    socket.AF_INET,
    socket.SOCK_DGRAM
)

udp_socket.bind(('192.168.0.4',8284)) 

print('init socket')


# %%

while True:
    print("wait request...")

    _data,_rinfo = udp_socket.recvfrom(1024)
    _packet = unpack("BBhf", _data) 
    # byte, byte, short, float  4byte 단위로 끊어주는게 좋다 ( 1,1,2,(4),  4)
    # c로 변환할때 4바이트 3바이트 이런식이면 마지막 바이트에 0이 추가되는 경우가 있다.

    if _packet[0] == 0x01:      # 패킷 헤더의 요청 01이면 캐릭터 hp 반환해라 뭐 이런식으로 로직 짤 수 있음
        _res = pack("BBHH", 0xa1, 0, 300, 400) # 응답 헤더라고 설정(01 에 대한 ) 0xa1로 설정
    elif _packet[0] == 0x02:    #요청 코드 2에 대한 처리
        _res = pack("BBHH", 0xa2, 0, 150, 200) 
    else :
        _res = pack("BBHH",0xff, 0, 0, 0) 

    print('response OK')
    udp_socket.sendto(_res,(_rinfo[0], _rinfo[1]))
        
# %%
