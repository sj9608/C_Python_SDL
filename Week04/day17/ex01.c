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
            szToken = strtok(NULL, " ");
            strcpy(_szBuf[0], szToken);
            //x
            szToken = strtok(NULL, " ");
            strcpy(_szBuf[1], szToken);
            //y
            szToken = strtok(NULL, " ");
            strcpy(_szBuf[2], szToken);
            //w
            szToken = strtok(NULL, " ");
            strcpy(_szBuf[3], szToken);
            //h
            szToken = strtok(NULL, " ");
            strcpy(_szBuf[4], szToken);

            // name parsing
            szToken = strtok(_szBuf[0], "="); // = 문자로 나눔 name 이란 글자가 얻어짐
            szToken = strtok(NULL, ".");      // . 문자로 나눔 --> "name 값이얻어짐
            strcpy(_szBuf[0], szToken + 1);   // char 형주소 1칸 만큼 뒤로간 값을 넣어줌 결과적으로 name 만 얻어진다.
            printf("%s\n", _szBuf);

            // x parsing 현재 x값은  _szBuf[1] 에 들어가있음.
            szToken = strtok(_szBuf[1], "\"");
            szToken = strtok(NULL, "\"");
            printf("x:%d\n", atoi(szToken));

            // y parsing
            szToken = strtok(_szBuf[2], "\"");
            szToken = strtok(NULL, "\"");
            printf("y:%d\n", atoi(szToken));

            // w parsing
            szToken = strtok(_szBuf[3], "\"");
            szToken = strtok(NULL, "\"");
            printf("w:%d\n", atoi(szToken));

            // y parsing
            szToken = strtok(_szBuf[4], "\"");
            szToken = strtok(NULL, "\"");
            printf("h:%d\n", atoi(szToken));
        }
    }

    fclose(fp);
    return 0;
}