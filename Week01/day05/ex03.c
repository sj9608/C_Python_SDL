#include <stdio.h>

int main()
{
    int _i = 0;
    printf("%d \n", _i++);              // 0
    printf("%d \n", _i);                // 1
    printf("%d \n", ++_i);              // 2
    printf("%d %d\n", ++_i, ++_i);      // 4 4 ???
    printf("%d %d\n", _i++, _i++);      // 5 4 ???

    /*
    In this statement, the expression "printf(...)" modifies the variable "i" more than once without an intervening sequence point.
    This behavior is undefined.
    The compiler has detect a case where the same variable has been modified more than once in an expression 
    without a sequence point between the modifications. 
    Because what modification will occur last is not defined, this expression might produce different results on different platforms.
    Rewrite the expression so that each variable is modified only once.

    even you might get output "2 3" in different compiler*/
    
    return 0;
}