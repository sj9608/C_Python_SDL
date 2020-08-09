// 332p. Q2) int형 변수 data에 값 0x12345678  data의 값을 직접변경하지 않고 short *형 포인터 변수선언한뒤 data변수의 값을 0x12340412로 변경하세요.
#include <stdio.h>

void main()
{
    int data = 0x12345678;

    short *ptr = &data;

    *(ptr+0) = 0x0412; //  data의 메모리 주소가 시작번지부터 78, 56, 34, 12 순서로 저장되어있다.  따라서 ptr의 시작주소 부터 12, 04 를 넣게되면 12, 04, 34, 12 --> 0x12340412가 된다.
    *(ptr+1) = 0x8765; 

    printf("%p \n", data);
}