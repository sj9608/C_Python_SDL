#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#define STUDENT_MAX 1000

int score[STUDENT_MAX][3]; // 성적
char name[STUDENT_MAX][8]; //이름
int _tailIndex = -1;       // 끝을 가리키는 인덱스

int main(int argc, char *argv[])
{
    char _sel_menu; // 메뉴선택
    SDL_bool bLoop = SDL_TRUE;

    while (bLoop)
    {

        char _sel_menu; // 메뉴선택
        printf("1. input score\n");
        printf("2. del score\n");
        printf("p. print score \n");
        printf("q. quit \n");

        _sel_menu = getchar();
        rewind(stdin);

        switch (_sel_menu)
        {
        case 'q':
            bLoop = SDL_FALSE;
            break;

        case '1':
            //lee,80,75,85
            printf("input score [name,kor,eng,math] \n");
            {
                char _tokenBuffer[32][8];
                char _c;
                int _tokenIndex = 0;
                int _index = 0;

                do
                {
                    _c = getchar();
                    if (_c == ',')
                    {
                        _tokenBuffer[_tokenIndex][_index] = 0x00;
                        _tokenIndex++;
                        _index = 0;
                        printf("%d \n", _tokenIndex);
                    }

                    else
                    {
                        _tokenBuffer[_tokenIndex][_index++] = _c;
                    }

                } while (_c != '\n');

                _tokenBuffer[_tokenIndex][_index] = 0x00;
                printf(("%s %s %s %s \n", _tokenBuffer[0], _tokenBuffer[1], _tokenBuffer[2], _tokenBuffer[3]));

                _tailIndex++;
                
                strcpy(name[_tailIndex], _tokenBuffer[0]);
                score[_tailIndex][0] = atoi(_tokenBuffer[1]);
                score[_tailIndex][1] = atoi(_tokenBuffer[2]);
                score[_tailIndex][2] = atoi(_tokenBuffer[3]);
            }

        case 'p':
            printf("--------------------------------\n");
            for (int i = 0; i <= _tailIndex; i++)
            {
                printf("%9s %4d %4d %4d\n", name[i], score[i][0], score[i][1], score[i][2]);
            }
            printf("press any key....");
            getchar();
            rewind(stdin);

        default:
            break;
        }
    }

    return 0;
}