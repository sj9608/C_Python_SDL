# 함수 포인터

## delegation pattern
상태제어할 때 많이 쓰인다.

# #define xxx xxx -> 전처리기
``` C
#define MSG "hello"
#define MYINT int

typedef int _MYINT;
// typdef와 define의 기능은 타입 재정의로 같다. 
// typdef로 선언하는게 좀더 유연하다. 컴파일시 전처리기 우선

puts(MSG); 
//puts("hello");
// 결과값은 "hello"
int a = 1;
MYINT a = 1;
_MYINT b = 1;
```
# #ifdef
``` C
void test()
{
    #ifdef __DEBUG__
    printf("debug mode\n");
    #endif
    printf("hello \n");
}

int main()
{
    test(); // 결과 값은 "hello"
    // void 함수 위에 #definde __DEBUG__ 있으면 결과값 "debug mode"
    // 보통 같은 소스파일 내에 디파인 하지 않고 컴파일당시 옵션
    // gcc -o $@ $^ -D __DEBUG__ 와 같은 형식으로 옵션을 넣어준다
}
```
# ifndef
``` if not define ```