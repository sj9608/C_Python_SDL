# %%


_f = open('t3.bin','rb')

buf = _f.read()

_f.close

#%%
from struct import *


#%%

# python struct 에 관련된 것은 google에 검색해보면 나온다.

_buf = unpack('fihBB', buf)

#%%
print(_buf)
# %%
