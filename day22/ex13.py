# 파이썬에서 이진데이터의 처리
# c언어 에서는 포인터를 이용했다.
# 파이썬과 c사이의 통신을 위해 처리해야함.

#%%

from struct import *

print(f'load struct module ')

# %%

# h 는 short 형  --> hhl 은 short 형 2개 , l 은 long 형 1개
buf = pack('hhl',1,2,3) 


# %%

u_buf = unpack('hhl', buf)

print(u_buf)

# %%
# 파일 만들고 쓰기 ( c에서 읽을 수 있다. )

_f = open('t1.bin', 'wb')
_f.write(buf)
_f.close()


# %%
