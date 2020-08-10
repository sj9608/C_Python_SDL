#%%
a = input()
b = input()

print( int(a) + int(b))

# %%
a = input()

print(a.split(' '))

# %%
a = [1,2,3,4,5,6,7,8,9]
print(a[0])

# %%
print(a[1:5])
print(a[:5])
print(a[3:])

# %%4
a[0] = 99
print(a)


# %%
a.append(30)

# %%
a.pop()

# %%
a=[1,2,3]


# %%
a.insert(0, 77)

# %%
a.insert(1, 80)

# %%
print(a)


# %%
#오름차순 인덱스 0~ 순서로 특정 값을 제거 (처음 만난 인덱스의 값)
a.remove(30)

# %%
a.sort()
print(a)

# %%
a = [5,4,3,2,1]
a.reverse()
print(a)

# %%
a = [1,2,3]
b = [4,5,6]
print(a+b)

# %%
#tuple
a = (1,2,3)

#%%
print(a[0])
print(a[:3])
# %%
a[0] = 9

# %%
type(a)

# %%
a, b, c = 1, 2, 3
print(a, b, c)

# %%
#packing
a = 1, 2, 3
type(a)

# %%
#unpacking
b, c, d = a
print(b, c, d)

# %%
# 딕셔너리 자료형은 자바스크립트랑 비슷함
# 몽고디비에서 이런식으로 db관리
dic = {}

# %%
dic['name'] = 'lee'

# %%
dic

# %%
dic['job'] = 'programmer'

# %%
dic.keys()

# %%
dic.values()

# %%
dic.items()


# %%
dic.clear()

# %%
