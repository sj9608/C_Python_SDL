#%%

import sys
import numpy as np

#%%

# 초기화 예
# 0~ 10 까지 1씩 증가하면서 만들어라
arr1 = np.arange(0, 10 , 1) 
print(arr1)

# %%

print(arr1[:])
print(arr1[1:7])

#%%

arr2 = np.zeros(10) # 0으로 10개 리스트
print(arr2) # 타입 안넣어주면 float 형으로 들어간다

# %%

arr3 = np.zeros(10, dtype = np.int32)
print(arr3)


# %%

# 1로 초기화
array_4 = np.ones(10, dtype= np.int32)
print(array_4)


# %%

# 3으로 초기화 one에서 곱해주면 됌
arr5 = np.ones(10, dtype= np.int32) * 3
print(arr5)


#%%

# 0~ 1 사이의 값을 랜덤하게
arr6 = np.random.rand(10)
print(arr6)

#%%

# 0~100 랜덤+ 정수
arr6 = np.random.rand(10)
print((arr6 * 100).astype(np.int32))
# %%

arr7 = (arr6 * 100).astype(np.int32)
print(arr7)

print(np.sort(arr7))
# %%

# 심화
# 인덱스만 정렬 하고싶을 때
arr8 = (arr6 * 100).astype(np.int32)
print(arr8)
print(np.argsort(arr8))


# %%

# 추가 심화

x1 = np.array([
    [1,9],
    [0,8],
    [6,3],
    [3,4],
    [4,1]
])

# 앞의 값을 기준으로 정렬 하고싶을 경우 
# ex) 1, 0, 6, 3, 4 기준 
# 배열의 첫번째 요소 값만 뽑아내는 방법
print(x1[:,0])

# 두번째 요소
print(x1[:,1])

# 정렬
print(x1[:,0].argsort())
print(x1[:,1].argsort())

# %%

# 첫번째 요소 기준으로 값을 출력하는 방법

sort_indexes = x1[:,0].argsort()
print(x1[sort_indexes[0]])

# %%

for  i in sort_indexes:
    print(x1[i])


# %%
