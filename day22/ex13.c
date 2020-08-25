#include <stdio.h>
#include <stdlib.h>

typedef struct _rp
{
    short *sp;
    short *sp2;
    int *ip;
} data;

int main()
{
    data *_data = malloc(sizeof(data));

    FILE *fp = fopen("t1.bin", "rb");

    fread(_data, sizeof(data), 1, fp);

    printf("0x%04x\n", _data->sp);
    printf("0x%04x\n", _data->sp2);
    printf("0x%04x\n", _data->ip);

    fclose(fp);

    return 0;
}