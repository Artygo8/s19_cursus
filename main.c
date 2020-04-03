#include "libs/ft_printf/ft_printf.h"

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : ' '), \
  (byte & 0x40 ? '1' : ' '), \
  (byte & 0x20 ? '1' : ' '), \
  (byte & 0x10 ? '1' : ' '), \
  (byte & 0x08 ? '1' : ' '), \
  (byte & 0x04 ? '1' : ' '), \
  (byte & 0x02 ? '1' : ' '), \
  (byte & 0x01 ? '1' : ' ') 

int backslash(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\\')
			count++;
		i++;
	}
	return (count);
}

int main()
{
	int i;

	i = 0;
	while (i++ < 128)
		printf(BYTE_TO_BINARY_PATTERN" %d = %c\n", BYTE_TO_BINARY(i), i, i);
}
