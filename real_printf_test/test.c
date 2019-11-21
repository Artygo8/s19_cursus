#include <stdio.h>

int main()
{
	printf("%s, %s %d, %.4d:%.4d\n", "thursday", "june", 8, 20, 8);
	printf("%s, %s, %*.2d:%.2d\n", "thursday", "june", 8, 20, 8);
	printf("%s, %s %d, %-4d:%-4d\n", "thursday", "june", 8, 20, 8);
	printf("%s, %s %d, %04d:%04d\n", "thursday", "june", 8, 20, 8);
	printf("%s, %s %d, %0-4d:%0-4d\n", "thursday", "june", 8, 20, 8);
	printf("%s, %s %d, %-04d:%-04d\n", "thursday", "june", 8, 20, 8);
	printf("hello %55555555%5555555\n", 1);
}
