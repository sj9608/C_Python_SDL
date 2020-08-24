#include <stdio.h>
#include <malloc.h>

int main()
{

    char a[][4] = {
        {0x1, 0x10, 0x00, 0x00},
        {0x2, 0x20, 0x00, 0x00},
        {0x3, 0x00, 0x30, 0x00},
        {0x4, 0x00, 0x40, 0x00},
        {0x5, 0x00, 0x00, 0x50},
    };

    int *a1, *a2, *a3, *a4, *a5;
    
    int sum;
    
    a1 = (int *)a[0];
    a2 = (int *)a[1];
    a3 = (int *)a[2];
    a4 = (int *)a[3];
    a5 = (int *)a[4];

    printf("0x%08x\n0x%08x\n0x%08x\n0x%08x\n0x%08x\n\n",*(a1), *(a2), *(a3), *(a4), *(a5));
    sum = (*(a1)) + (*(a2)) + (*(a3)) + (*(a4)) + (*(a5));
    printf("sum : 0x%08x\n", sum);
    // 리틀 엔디언

    printf("-------------------------\n");
    // 빅 엔디언 (뒤집어서)
    char _temp[4];
    int _a1, _a2, _a3, _a4, _a5;

    _temp[0] = a[0][3];
    _temp[1] = a[0][2];
    _temp[2] = a[0][1];
    _temp[3] = a[0][0];

    _a1 = *(int *)_temp;
    printf("0x%08x\n", _a1);

    _temp[0] = a[1][3];
    _temp[1] = a[1][2];
    _temp[2] = a[1][1];
    _temp[3] = a[1][0];

    
    _a2 = *((int *)_temp);
    printf("0x%08x\n", _a2);

    _temp[0] = a[2][3];
    _temp[1] = a[2][2];
    _temp[2] = a[2][1];
    _temp[3] = a[2][0];

    
    _a3 = *((int *)_temp);
    printf("0x%08x\n", _a3);

    _temp[0] = a[3][3];
    _temp[1] = a[3][2];
    _temp[2] = a[3][1];
    _temp[3] = a[3][0];

    
    _a4 = *((int *)_temp);
    printf("0x%08x\n", _a4);

    _temp[0] = a[4][3];
    _temp[1] = a[4][2];
    _temp[2] = a[4][1];
    _temp[3] = a[4][0];

    
    _a5 = *((int *)_temp);
    printf("0x%08x\n", _a5);

    


   

    

   

    return 0;
}