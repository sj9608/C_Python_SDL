#include <stdio.h>

int main()
{
    int data = 10;

    puts("inputs : ");
    scanf("%d", &data);
    
    if (data == 10)
    {
        data = 0;
    }

    //if (data != 10)
    else
    {
        data++;
    }

    printf("%d \n", data);

    return 0;  
}