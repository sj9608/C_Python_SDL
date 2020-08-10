#include <stdio.h>

int main()
{

    int *pa;
    int num = 3;
    int num2 = 9;
    const int *pb;
    int *const pc = &num2;

    pa = &num;
    pb = pa;
    // *pb = 7; -> const int * 형으로 선언 했기 떄문에 값변경이 불가능함. 
    *pa = 7;
    // pc = pa; int *const 형 으로 선언 했기 떄문에 주소값 변경이 불가능함

    printf("%d %d", &pb, *pc);

    return 0;

}