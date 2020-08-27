#%%

import sys
import numpy as np

print(f'numpy version {np.__version__}')

# numpy 는 기본적으로 array
# 초기화는 list 형식으로

# %%

data1 = [1,2,3,4,5]
print(type(data1))


#%%

array_1 = np.array(data1)
print(type(array_1))
print(array_1)

# %%

# dtype 멤버 변수 --> data 타입을 구할 수 있다.
print(f'data type : {array_1.dtype}')


# %%

# 차원구하기
print(array_1.shape)
#(5, ) --> 1차원 배열 이라는 뜻

# %%

data2 = [[1,2],[3,4], [5,6]]
array2 = np.array(data2)
print(array2.shape)


# %%

data3 = [1.1, 3.3, 2.2]
array3 = np.array(data3)
print(array3.dtype)


# %%
array3.astype(np.int32)
print(array3)
print(array3.dtype)
print("------------------") # 이 윗부분 자체가 바뀌지 않는다. 반환할뿐
# 반환받을 데이터를 지정해줘야한다. 

_array3 = array3.astype(np.int32)
print(_array3)
print(_array3.dtype)



# %%

data4 = np.array([1,2,3,4,5])
print(data4)

# data4 의 모든 요소에 10을 곱한 리스트를 반환한다. 

_data4 = data4 * 10
print(_data4)


# %%

print(data4[0:4])

# 이러한 변형도 가능하다
print(data4[0:2] * 10)

# %%

data5 = np.array(['a','b','c','d', 'e'])
print(data5)

# data4의 요소가 2보다 크면
#  data5의 요소의 해당 인덱스에 해당하는 값을 '-' 로 치환 
data5[data4 > 2] = '-'
print(data5)

#%%

_a1 = np.array([1,2,3,4,5,6,7,8,9])
_a2 = np.array([11,12,13,14,15])
print(_a1)
_a1[2:5] = _a2[1:4]
print(_a1)