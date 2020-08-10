#include <stdio.h>

int main()
{
    int _i = 5;
    printf("%d \n", _i);
    // i = i + 1; add
    _i++; // asembly language --> inc operator
    printf("%d \n", _i);

    int _a = _i++;      //first, _a = i after ++ operation
    printf("%d \n",_a); // conclusion _a = 6 
    printf("%d \n", _i);

    _a = ++_i;
    printf("%d \n", _a);

    return 0;
}