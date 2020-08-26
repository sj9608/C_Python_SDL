// ex02.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>

typedef struct MyStruct
{
    char Name[32];
    unsigned short x;
    unsigned short y;
    unsigned short w;
    unsigned short h;
} S_SHEET;

int main()
{
    static unsigned char buf[10000];

    FILE *fp = fopen("../sheet2.bin", "rb");

    // fread(buf, 10000, 1, fp);
    fseek(fp, 0, SEEK_END);
    int _size = ftell(fp);

    int _count = _size / sizeof(S_SHEET);

    // 이 윗부분 까지 함수로 따로 뺼 수 있음.

    // S_SHEET *ptr = (S_SHEET *)buf;
    // for (int i = 0; i < _count; i++)
    // {
    //     printf("%32s,%4d,%4d,%4d,%4d\n",ptr->Name[i] ,ptr->x, ptr->y, ptr->w, ptr->h);
    //     ptr++;
    // }

    void* ptrBuf = malloc(_count * sizeof(S_SHEET));
    fread(ptrBuf, sizeof(S_SHEET),_count,fp);
    
    for (int i = 0; i < _count; i++)
    {
        S_SHEET *pSheet = ((S_SHEET *)ptrBuf + i);
        printf("%32s,%4d,%4d,%4d,%4d\n",pSheet->Name ,pSheet->x, pSheet->y, pSheet->w, pSheet->h);
        
    }

    fclose(fp);

    return 0;
}