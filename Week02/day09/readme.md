# Today Learning in A.M.

## 포인터 변수의 주소연산
``` C
const int * // 값 변경불가
int * const // 주소 변경불가
int *(4) short *(2) char *(1) //각 포인터의 (메모리 크기)
```

## void *(?)
* 특징 
01. C 다형성 구현
02. 형식을 구체적으로 특정하지 않은 형태
03. type casting을 통해 원하는 형식으로 그때그때 바꿔 쓰는 용도

## type casting의 형태
 ```
 (int *)_void_value, (char *)_void_value, (Uint16 *)_void_value
 ```
 
 # Today Learning in P.M.

 ## 표준 입력함수
 ``` C
 scanf, getchar, gets
```
## getchar, gets 함수
getchar 함수는 말그대로 문자 하나를 입력받는다\
getchar 함수를 쓰고난뒤에는\
rewind(stdin) 함수를 사용해줘야함
***
gets 함수는 문자열을 입력받는다.\
gets 함수가 동작 하지 않는다면 fgets 함수를 입력해보자\
컴파일러마다 달라서 생기는 일이다.

## 입력받은 문자열 정수로 전환하기
``` C
#include <stdio.h>
#include <string.h>

// 문자열 -> 정수형 변환
int main()
{
    char strBuf[32];
    printf("input number : ");
    gets(strBuf);

    int num  = 0;

    printf("str length %d \n", strlen(strBuf));
    // 문자열 길이 구하는 함수는 반복문으로 카운트 증가시키며 0찾으면됌


    int count = strlen(strBuf);
    int pos_num = 1;
    for(int i = 0; i < count-1 ; i++)
    {
        pos_num *= 10;
    }
    
    printf("max pos_num : %d \n", pos_num);

    for(int i = 0 ; i<count ; i++)
    {
        num = num + (strBuf[i] - '0') * pos_num;
        pos_num /= 10;
    }
    printf("%s = > %d \n", strBuf, num);
    

    return 0;
}
```
## 더 간단히 문자열을 정수로 바꾸기
``` C
// C언어 에서는 atoi 라는 함수를 제공함 
#include <stdlib.h> // 헤더 추가
char _num = "123";
int _atoiNum ;
_atoiNum = atoi(_num); 
// atoi 함수를 통해 간단하게 문자열을 정수로 바꿀 수 있다.
```

# Scanf 함수
scanf는 scan format 을 줄인 이름이다.\
이 함수는 다양한 키워드를 사용하여 문자. 문자열, 정수, 실수 까지\
모두 입력받을 수 있도록 형식화된 입력을 제공한다.

## 01. scanf 함수에서 & 연산자를 사용하는 이유.
getchar 함수에서는 return문을 통하여 하나씩 값을 반환해주지만\
scanf 에서는 여러개의 값을 동시에 입력 받아야 하기 떄문에 return문을 사용 할 수 없다. 그로인해 포인터를 통해 입력값을 저장할 두변수의 주소를 활용함.\
``` 
scanf에서 값의 구분은 enter 또는 공백으로한다.
```

## 02. scanf 함수 사용시 주의할 점
scanf 함수로 값을 받을 때에는 공백이 들어간다면 공백 이전의 값만 저장되고\
나머지는 입력버퍼에 남아있게 된다.\
이로인해 다음표준입력함수에 영향을 줄수 있기 때문에 \
공백이들어간다면 gets함수를 사용하는것이 더 좋다.\
gets함수를 사용하면 배열의 마지막에 enter 값이 들어가기 때문에\
문자열을 합치거나 할경우에 마지막 값을 0으로 초기화 시켜줘야함.