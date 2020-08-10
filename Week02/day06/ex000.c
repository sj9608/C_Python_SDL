//변수의 값을 2진수 형태로 변환하는 예제.
#include <stdio.h>

unsigned char getBit(unsigned char dest_data, unsigned char bit_num)
{
  unsigned char bit_state = 0;
  // 1byte so. only 0~7 bit can shift.

  if(bit_num < 8)
  {
    bit_state = dest_data & (0x01 << bit_num);
    bit_state = bit_state >> bit_num;
  }

  return bit_state;
}

void main()
{
  unsigned char lamp_state = 0x75;
  unsigned char bit_state;
  int i;

  printf("%x -> ", lamp_state);

  for(i = 0; i < 8; i++)
  {
    bit_state = getBit(lamp_state, 7-i);
    printf("%d", bit_state);
  }

  printf("\n");
  
}