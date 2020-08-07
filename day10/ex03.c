#include <stdio.h>

int main()
{
    int data[5] = {1, 2, 3, 4, 5};
    int *p = data;
    for(int i = 0 ; i < 5; i++)
    {
        // printf("%d \n", data[i]);

        // printf("%d \n",*p);
        // p++;
        
        printf("%d \n",*(p ++));
    }
    return 0;
}