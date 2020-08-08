// 287p. Q2) data배열의 짝수 번째 요소에 저장된 값을 합산하는 코드를 작성해보세요
#include <stdio.h>
#include <string.h>

short _sum_Even(short _data[], int _dataSize)
{
    int rst = 0;

    for (int i = 0; i < _dataSize; i += 2)
    {
        rst += _data[i];
    }

    return rst;
}

// 287p. Q3) data 배열의 각 요소에 저장된 갑 중에서 가장 큰 값을 찾는 코드를 작성해 보세요.
short _find_Max(short _data[], int _dataSize)
{
    int _MAX = 0;

    for (int i = 0; i < _dataSize; i++)
    {
        if (_MAX < _data[i])
        {
            _MAX = _data[i];
        }
    }

    return _MAX;
}

void main()
{
    short data[9] = {4, 6, 9, 8, 7, 2, 5, 1, 3};
    int _arraySize = sizeof(data) / sizeof(*data);
    printf("size of data is : %d\n", sizeof(data)); // short data has 2byte So 9 arrays have 2 * 9 = 18 bytes
    printf("Sum_EvenIndexValue in data is %d \n", _sum_Even(data, _arraySize)); // expect value is 27
    printf("MAX value in data is : %d \n",_find_Max(data, _arraySize)); // expect value is 9
}

// DONE: 21:53 08-08-20 Is there a printing data type function like type(variable) in python ? DONE:
// TODO: remove functions parameter2(_datasize) how can get DataSize in function ??