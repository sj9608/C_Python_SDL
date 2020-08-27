# %%

import socket
from struct import *

udp_socket = socket.socket(
    socket.AF_INET,
    socket.SOCK_DGRAM
)

udp_socket.bind(('192.168.0.4', 8284))

print('init socket')


# %%
def packet_process() :
    while True:
        print("wait request...")

        _data, _rinfo = udp_socket.recvfrom(1024)
        _packet = unpack("BBHH", _data)
        # byte, byte, short, float  4byte 단위로 끊어주는게 좋다 ( 1,1,2,(4),  4)
        # c로 변환할때 4바이트 3바이트 이런식이면 마지막 바이트에 0이 추가되는 경우가 있다.

        if _packet[0] == 0x01:      # 패킷 헤더의 요청 01이면 캐릭터 hp 반환해라 뭐 이런식으로 로직 짤 수 있음
            if _packet[1] == 0x01:  # 덧셈 처리
                _res = pack("Bh", 0x01, _packet[2] + _packet[3])
            elif _packet[1] == 0x02:  # 뺄셈 처리
                _res = pack("Bh", 0x02, _packet[2] - _packet[3])
            elif _packet[1] == 0x03:  # 곱셈 처리
                _res = pack("Bh", 0x03, _packet[2] * _packet[3])
            elif _packet[1] == 0x04:  # 나눗셈 처리
                _res = pack("Bh", 0x04, _packet[2] / _packet[3])
        else:
            _res = pack("Bh", 0xff, 0)

        print('response OK')
        udp_socket.sendto(_res, (_rinfo[0], _rinfo[1]))

import threading

_serverThread = threading.Thread(target = packet_process) # 메인 함수가 스레드 하나.
_serverThread.daemon = True # 주 서버가 죽으면 같이 다운
_serverThread.start() # 서버 실행 

while True:
    print('input cmd : ')
    cmd = input()
    if cmd == 'exit':
        break
# %%
