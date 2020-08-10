#include <stdio.h>

int main()
{
    int data[2] = {0x12345678, 0x12345678};
    
    printf("%8x \n", data[0]);

    //data[0] = 0x22 아래와 같음 
    // *(data+0) = 0x22;
    // printf("%x \n", data[0]); 

    //일시적 형변환을 통해 값을 바꿔줄 수 있다
    *(char *)(data+0) = 0x00;
    printf("%8x \n", data[0]);

    //data[1] 의 값을 0x12005678; 로 바꾸기
    *((char *)data + 6) = 0x00;
    printf("%8x \n", data[1]);

    return 0;
}