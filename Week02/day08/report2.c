#include <stdio.h>
#include <stdlib.h>

void _aSort(int __nA[])
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = i+1 ; j < 101; j++)
        {
            if(__nA[i] > __nA[j])
            {
                int _tmp = __nA[i];
                __nA[i] = __nA[j];
                __nA[j] = _tmp;
            }
        }
    }
}

int main()
{
    int nA[100] = {0};

    for (int i = 0; i < 100; i++)
    {
        nA[i] = rand() % 100;
        printf("%3d", nA[i]);
    }
    
    printf("\n");
    _aSort(nA);

    for (int i = 0; i < 100; i++)
    {
        printf("%3d", nA[i]);
    }

    return 0;
}