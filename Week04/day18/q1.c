/* quiz1. sheet.dat  binary 파일을 읽은뒤 
그안에 저장되어있는 8byte는 이름으로 나머지는 2byte로 출력
8 byte => name
2 byte => x
2 byte => y
2 byte => w
2 byte =>h
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 우선 8byte, 2,2,2,2 나누기 위해 구조체로 선언
typedef struct _s_sheetData
{
    char name[8];
    short x;
    short y;
    short w;
    short h;
} sheetData;

int main()
{
    sheetData *data = {malloc(sizeof(sheetData)), };

    // open file을 담을 포인터 변수선언 sheet.data file open as rb
    FILE *fp = fopen("sheet.dat", "rb");

    
    while(fread(data, sizeof(sheetData), 1, fp))
    {
        printf("%8s%4x%4x%4x\n", data->name, data->x, data->y, data->w, data->h);
    }
    free(data);
    fclose(fp);

    return 0;
}