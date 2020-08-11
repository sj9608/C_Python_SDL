# How to Use fopen( )
``` cmd
fopen("file name", "rwt")
```
t -> text\
b -> binary\

r -> 읽기 모드\
w -> 쓰기 모드\
a -> 이어쓰기

\+ -> rw모드 , 강조모드

r+ ->
w+ -> 파일 없으면 만들기, 기존파일을 삭제하고 새로 만듬\
w  -> 파일 없으면 만들기, 기존파일을 유지한다.\
a -> 이어서 쓰기 (append)

wb -> 바이너리 쓰기모드\
rt -> 텍스트 읽기모드\
rw -> 텍스트 읽기 쓰기 모드