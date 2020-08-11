#include <stdio.h>

int main()
{
    unsigned char data[8] ={10, 20, 30, 40, 50, 60, 70, 80};

    FILE *fp;
    fp = fopen("test.bin", "wb");

    fwrite(data, sizeof(unsigned char),8,fp); // 8byte data print

    fclose(fp);

    return 0;
}