_a = "hello"
_b = "libex04"
_c = "libex03"

_a.startswith('he')
_a.endswith('lo') #_a라는 문자열이 'lo'라는 문자열로 끝나는지 확인하고 T, F 값 반환

_b.startswith('lib') # _b라는 문자열이 'lib'라는 문자열로 시작하는지 확인하고 T,F값 반환

_a.find('ex')  # a 문자열안에 'ex' 라는 문자가 있는지 찾을 때

_a.count('l') # _a라는 문자열 안에 'l' 이라는 문자의 개수 반환

_lt = "       front line         "  #원본 스트링

_lt.lstrip() #왼쪽에 있는 공백을 없애는 함수
_lt.rstrip()

__lt = _lt.lstrip() # 이런 식으로 원본은 남겨두고 사본으로 넘겨주는 처리를함.

print('\'' + _lt + '\'')  #위에서 lstrip, rstrip 모두 진행 했지만 원본에는 변함없음

print(str.isalpha('hello')) # 영문자 인지 확인하고 T, F값 반환

print(str.isdigit('hello')) # 숫자인지 확인하고 T, F값 반환

#python 에서 printf 함수 사용하는 방법
name = 'lsj'
age = 25
print(f'my name {name} my age {age}') 

print(str.format("my name %s my age %d", name, age)) # 아직 모름

data = "lee seung jun"
print(data.split()) # 배열로 공백기준 해서 출력

_data = data.split()

print(_data[0])
print(_data[1])
print(_data[2])

data = "kor/eng/mat/sci"
_data = data.split('/')
print(_data)


#입력받는 함수
data = input()
_data = data.split()
print(_data)