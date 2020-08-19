// xml file parsing practice
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 이름, x, y, w, h 값을 잘라야함
// 이름은 char, 나머지 int형 => 구조체로 선언

typedef struct __s_sheet_data
{
    char szName[32];
    int x;
    int y;
    int w;
    int h;
} _S_SheetData;

int main()
{
    static char szBuf[256];

    FILE *fp = fopen("res/sheet_tanks.xml","rt");

    
    
    
    while(fgets(szBuf,sizeof(szBuf), fp))
    {
        char *szToken = strtok(szBuf, " ");
        // if(!)
        printf("%s",szToken);
    }

    return 0;
}