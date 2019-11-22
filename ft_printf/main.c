#include "ft_printf.h"

int main()
{
	printf("====================================\n");
	printf("=============MY PRINTF==============\n");
	printf("====================================\n");
	printf("\n");
	ft_printf("%s = %x\n", "%x 2000000", 2000000);
	ft_printf("%s = %X\n", "%X 123", 123);
	ft_printf("%s = %%\n", "%%");
	ft_printf("%s = %.4s\n", "%.4s", "hello world!");
	ft_printf("%s = %.4d\n", "%.4d", -123);
	ft_printf("%s = %.3p\n", "%.3p", 1);
	ft_printf("%s = %.4%\n", "%.4%", 0);
	printf("\n");
	printf("====================================\n");
	printf("=============LIB PRINTF=============\n");
	printf("====================================\n");
	printf("\n");
	printf("%s = %x\n", "%x 2000000", 2000000);
	printf("%s = %X\n", "%X 123", 123);
	printf("%s = %%\n", "%%");
	printf("%s = %.4s\n", "%.4s", "hello world!");
	printf("%s = %.4d\n", "%.4d", -123);
	printf("%s = %.3p\n", "%.3p", 1);
	printf("%s = %.4%\n", "%.4%", 0);
	printf("\n");
	printf("====================================\n");
	printf("=============MY PRINTF==============\n");
	printf("====================================\n");
	printf("\n");
	ft_printf("%s = %5x\n", "%5x 2000000", 2000000);
	printf("%s = %-20Xyoyoyoo\n", "%20X 123", 123);
	ft_printf("%s = %%\n", "%%");
	ft_printf("%s = %.4s\n", "%.4s", "hello world!");
	ft_printf("%s = %.4d\n", "%.4d", -123);
	ft_printf("%s = %.3p\n", "%.3p", 1);
	ft_printf("%s = %.4%\n", "%.4%", 0);
	ft_printf("%s = %.4u\n", "%.4u", -33);
	ft_printf("%s = %*d\n", "%.4u", 40, 5);
	ft_printf("%s = %p\n", "%p 0", 0);
	ft_printf("%s = %p\n", "%p 1", 1);
	ft_printf("%s = %p\n", "%p NULL", NULL);
	ft_printf("%s = %s\n", "%s NULL", NULL);
	ft_printf("%s = %s\n", "%s NULL", "");
	printf("\n");
	printf("====================================\n");
	printf("=============LIB PRINTF=============\n");
	printf("====================================\n");
	printf("\n");
	printf("%s = %5x\n", "%5x 2000000", 2000000);
	printf("%s = %-20Xyoyoyoo\n", "%20X 123", 123);
	printf("%s = %%\n", "%%");
	printf("%s = %.4s\n", "%.4s", "hello world!");
	printf("%s = %.4d\n", "%.4d", -123);
	printf("%s = %.3p\n", "%.3p", 1);
	printf("%s = %.4%\n", "%.4%", 0);
	printf("%s = %.4u\n", "%.4u", -33);
	printf("%s = %*d\n", "%.4u", 40, 5);
	printf("%s = %p\n", "%p 0", 0);
	printf("%s = %p\n", "%p 1", 1);
	printf("%s = %p\n", "%p NULL", NULL);
	printf("%s = %s\n", "%s NULL", NULL);
	printf("%s = %s\n", "%s NULL", "");

	printf("\n");

	return 0;
}

//c, % se fout de la precision
//p applique la precision avant de mettre l'intro
//p d i u x X
