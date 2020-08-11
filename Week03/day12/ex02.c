#include <stdio.h>

struct Test1
{
    char a;
    double b;
    short c;
    char d;
};

struct Test2
{
    char a;
    char d;
    short c;
    double b;
};

int main()
{
    printf("Test1 :%d, Test2 : %d", sizeof(struct Test1), sizeof(struct Test2));
    return 0;
}
