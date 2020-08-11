#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// const int  STUDENT_MAX = 1000;
#define STUDENT_MAX 1000

int score[STUDENT_MAX][3]; //성적
char name[STUDENT_MAX][8]; //이름
int tail_Index = -1;

int main()
{

  bool bLoop = true;
  while (bLoop)
  {
    char _sel_menu;

    printf("1. input score \n");
    printf("2. del score \n");
    printf("3. edit score \n");
    printf("4. get total score \n");
    printf("5. get average \n");
    printf("p. print score \n");
    printf("q. quit \n");

    _sel_menu = getchar();
    rewind(stdin);
    switch (_sel_menu)
    {
    case '1':
    //lee,80,70,85
      printf("input score [name kor eng math] \n");
      {
        char _tokenBuffer[32][8];
        int _tokenIndex = 0;
        int _index = 0;

        char _c;
        do {
          _c = getchar();
          
          if(_c == ' ') {  //02. ' '만나면 토큰인덱스 0번에 입력마치고(배열의 마지막에 0값 넣어줌) 토큰인덱스 올리고 인덱스0초기화해서 국어점수값 받을준비 반복하다가
            _tokenBuffer[_tokenIndex][_index] = 0x00;
            _tokenIndex++;
            _index = 0;          
          }
          else // 01. 문자 입력한거 순서대로 넣어주면서 인덱스 올려줌
          {
            _tokenBuffer[_tokenIndex][_index++] = _c;
          }
        } while(_c != '\n'); // 03. enter 키 입력받으면 1줄 입력완료

        _tokenBuffer[_tokenIndex][_index] = 0x00; // 04. 입력이 끝났으면 입력버퍼를 초기화해줌

        printf("%s %s %s %s \n",_tokenBuffer[0],_tokenBuffer[1],_tokenBuffer[2],_tokenBuffer[3]); //입력이 완료된 버퍼의 값들을 출력(확인용도)
        
        tail_Index++; // tail index값 증가시켜줘서 다음학생 정보 입력받을준비
        strcpy(name[tail_Index],_tokenBuffer[0]);
        score[tail_Index][0] = atoi(_tokenBuffer[1]);
        score[tail_Index][1] = atoi(_tokenBuffer[2]);
        score[tail_Index][2] = atoi(_tokenBuffer[3]);

        //bLoop = SDL_FALSE;
      }
      break;
    case 'p':
      {
        printf("---------------------------\n");
        for(int i=0;i<=tail_Index;i++)
        {
          printf("%8s%4d%4d%4d\n",name[i],score[i][0],score[i][1],score[i][2]);
        }
        printf("press any key......");
        getchar();
        rewind(stdin);
      }
      break;
    case 'q':
      bLoop = false;
      break;

    default:
      break;
    }
  }

  return 0;
}
