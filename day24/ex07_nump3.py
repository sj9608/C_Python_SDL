#%%

import sys
import numpy as np

#%%

# for문과 numpy 두가지 동시에 활용하기

_test_np = np.arange(1,10 ,1)
print(_test_np)


# %%

print(type(_test_np))

# %%

# ndarray 타입을 list 형태로 바꾸기
list1 = [value for value in _test_np]
print(list1)
print(type(list1))

# %%

# 이 방법을 축약한게 위에 셀
list2 = []
for value in _test_np:
    list2.append(value)
print(list2)


# %%

# 응용 버전

list3 = [value for value in _test_np if value%2]
# 짝수일 때는 false --> 홀수만 들어감

print(list3)
# %%

array1 = (np.random.rand(5) * 10).astype(np.int32)
array2 = (np.random.rand(5) * 10).astype(np.int32)

print(array1)
print(array2)


# %%

# 위의 두개의 배열을 쌍으로 만드는 방법

print([_v for _v in zip(array1,array2)])
# 튜플로 변환됌


# %%

# 배열의 첫 번째 요소가
# 5보다 큰 값만 튜플로 묶고싶다.
print([_v for _v in zip(array1,array2) if _v[0] >= 5])


# %%
