#include <stdio.h>

int _FM(short _data[])
{
    int i, j, _max = 0;
    for (i = 0; i < 9; i++)
    {

        if (_max < _data[i])
        {
            _max = _data[i];
        }
    }
    return _max;
}

int main()
{
    short data[9] = {4, 6, 9, 8, 7, 2, 5, 1, 3};

    printf("%d" ,_FM(data));

    return 0;
}