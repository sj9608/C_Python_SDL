#include <stdio.h>

int main()
{
    char name[32];

    printf("input name : ");
    scanf("%s", name);

    printf("my name is : %s", name); //scanf 단점 : 공백인식 못함 띄어서쓰면 공백앞까지만 인식함.

    return 0;
}