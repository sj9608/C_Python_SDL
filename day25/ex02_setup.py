# C 를 DLL 로 만들어 주기 위한 Python Script
from distutils.core import setup, Extension

setup(name="_ex02",  # 모듈이름 불러오기
      version="1.0",
      description="_ex02",  # 설명
      author="KINOTZ",
      author_email="sneak7581@wku.ac.kr",
      url="https://github.com/sneak7581",
      ext_modules=[Extension("_ex02",["ex02_py_mod.c"])] # 모듈 이름, 컴파일할 파일 이름
      )
