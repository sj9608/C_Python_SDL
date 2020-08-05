# Day08 Learning in A.M.
vs2019 작업환경 vscode로 이전하기
01. Developer Command Prompt Vs2019 -> cd 작업폴더 (현재 C:\Users\sneak7581\Desktop\c_python_pad) -> code .
02. 터미널에서 cl.exe가 실행 되는지 확인 

## 2중 for문 으로 텍스트 그래픽 만들기
``` bash
****
****
****
****
```
``` bash
*
**
***
****
```

트리모양
``` bash
  *
 ***
*****
 ***
  *
```

# 2차원 배열
#### 2 차원 인덱스를 1차원으로 만들기
[1][1] = 5
[1][2] = 6

*행번호 * 열갯수 + 열번호 = 1차원 인덱스*
***
#### 1 차원 인덱스를 2차원으로 만들기

1차원 인덱스 / 열갯수 = 행번호
1차원 인덱스 % 열갯수 = 열번호

# Day08 Learning in P.M.
* ASM파일 생성하는 방법
``` bash
$ gcc -S -o ex05.asm ex05.c 
```
asembly language 설명 \$1 은 값 1 을 의미함 \$ 표시가 없으면 주소값
``` bash
movl	$1, 28(%esp) 
```
``` C
movl	$1, 12(%esp) // 값 -> 메모리
movl	$2, 8(%esp)
movl	12(%esp), %edx // 메모리 -> 레지스터
```

## 포인터
& -> 주소 연산자
call by reference -> 컴파일러가 관리함
call by pointer -> 메모리에서 관리함 (내가 잘 관리해야함)