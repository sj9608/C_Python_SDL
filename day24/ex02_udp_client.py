#%%

import socket
from struct import *

udp_socket = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

print('init socket')


#%%

# 데이터 전송을 하려면 packing 을 해서 보내야함 sendto 전에
_buf = pack("BBhh",0x01, 0x03, 4, 5)

udp_socket.sendto(_buf,('192.168.0.4',8284))

print('send data')

_data,_rinfo = udp_socket.recvfrom(1024)
_res = unpack("Bh", _data) 
print(_res)


# %%
