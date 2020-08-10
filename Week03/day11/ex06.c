#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main()
{
    char **pNames;
    int _count; // 인원수 입력받기
    printf("input pepople count : ");
    scanf("%d", &_count);
    rewind(stdin);

    pNames = (char **)malloc(sizeof(char *) * _count); // 인원수 만큼 할당

    for (int i = 0; i < _count; i++) //이름에대한 할당
    {
        char buf[32];
        gets(buf);                   // 이름입력 버퍼
        int _size = strlen(buf) + 1; //
        pNames[i] = (char *)malloc(_size);
        strcpy(pNames[i], buf); //
        // pNames++ // 그 다음 번지에 대해 반복
    }
    printf("-------------");
    for (int i = 0; i < _count; i++)
    {
        printf("names %s\n", pNames[i]);
    }
    for (int i = 0; i < _count; i++)
    {
        free(pNames[i]);
    }
}