# C, Python  파이썬에 있는 함수를 C에서 호출하는 방법


``` bash 
Python ex01_setup.py build_ext --inplace
```

* python 인터프리터에서 실행하기

``` Python
import _ex02
print(_ex02.__doc__)
_ex02.hello()
_ex02_c_add(4,5)
```

# vc2019 에서 OpenCV 셋팅하기

[https://yyman.tistory.com/1330] 

# tensorflow 설치

base : conda 에서 진행하지말것

새로운 env 생성

```
conda create -n 환경이름
```

변경 
```
conda activate 환경이름
```

# xor 학습 시키는 간단한 ai 예제