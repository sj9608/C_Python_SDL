# C, Python  파이썬에 있는 함수를 C에서 호출하는 방법


``` bash 
Python ex01_setup.py build_ext --inplace
```

python 인터프리터에서 실행하기

``` Python
import _ex02
print(_ex02.__doc__)
_ex02.hello()
```