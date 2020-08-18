#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct __s_sheet_data
{
    char szName[32];
    int x;
    int y;
    int w;
    int h;
} _S_SheetData;

void parseSheet(const char *szStr, _S_SheetData *pData)
{
    static char _szBuf[5][256];
    
}

int main()
{
    static char szBuf[256];

    FILE *fp = fopen("../../res/tanks/sheet_tanks.xml", "rt"); // read text
    /*
    fgets(szBuf, sizeof(szBuf), fp); //첫번째 토큰
    char *szToken = strtok(szBuf, " ");
    printf("%s\n", szToken);
    szToken = strtok(NULL, " "); // 첫번째 토큰이빠지고 그다음토큰이 들어감
    printf("%s\n",szToken);
    */

    // 한줄씩 읽는 함수 scanf 하지만 공백 만나면 끝..
    // fgets 함수로 읽어야함
    while (fgets(szBuf, sizeof(szBuf), fp))
    {
        //szBuf 은 한줄한줄 읽는데 그 한줄한줄에서 조각내는기능을 구현해야함
        char *szToken = strtok(szBuf, " ");    //위에 한줄날리고
        if (!strcmp(szToken, "\t<SubTexture")) // 그다음줄에 <SubTexture 까지 날림
        {
            // 각 요소를 저장할 배열생성
            static char _szBuf[5][256]; //5 는 name,x,y,w,h가 들어갈공간 256은 문자하나하나 넣어줄공간

            //name
            szToken = strtok(szBuf, "\"");
            szToken = strtok(NULL, "\"");

            strcpy(_szBuf[0], szToken);
            printf("%s\n",_szBuf);
            
        }
    }

    fclose(fp);
    return 0;
}