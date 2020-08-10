#include <stdio.h>

typedef struct 
{
    char szName[32];
    int kor;
    int eng;
    int math;
} s_Score;

void setScoreData(s_Score *pScore)
{
    scanf("%s %d %d %d",
    (*pScore).szName,
    &(pScore->kor), //(*pScore.kor)
    &(pScore->eng),
    &(pScore->math));
}

int main()
{
    s_Score _score;
    printf("input Name, kor, eng, math : ");
    setScoreData(&_score);

    printf("name : %-8s \n",_score.szName);
    printf("kor : %d \n",_score.kor);
    printf("eng : %d \n",_score.eng);
    printf("math : %d \n",_score.math);

    return 0;
}
