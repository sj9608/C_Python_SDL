// 366p 연습문제 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _stract(char _data1[], char _data2[])
{
    char _dst1[32];
    int i;
    for(i = 0; i < strlen(_data1); i++)
    {
        _dst1[i] = _data1[i];
    }
    for(i = strlen(_data1) ; i < strlen(_data1)*2 + strlen(_data2); i++)
    {
        _dst1[i] = _data2[strlen(_data1)- i];
    }
    printf("%s \n",_dst1);
}

void main()
{
    char _strBuf1[32], _strBuf2[32];
    gets(_strBuf1);
    gets(_strBuf2);

    printf("%s , %s\n",_strBuf1, _strBuf2);

    _stract(_strBuf1,_strBuf2);
}

//366p 연습문제 1.
/*
#include <stdio.h>

void main()
{
    int _arr[3] = {0}, i, _sum;

    scanf("%d %d %d",&_arr[0], &_arr[1], &_arr[2]);
    _sum = (_arr[0] + _arr[1] + _arr[2]) / 3;
    printf("avg is : %d\n", _sum);

}
*/