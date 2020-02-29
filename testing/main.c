#include "test.h"

int	test_atoi_base()
{
	printf("\n--- test ft_atoi_base.c VS ft_atoi_base.s ---\n\n");
	printf("ft_atoi_base.c : %d\n", ft_atoi_base_c("11110000111", "01"));
	printf("ft_atoi_base.s : %d\n", ft_atoi_base("11110000111", "01"));
	return (1);
}

int main()
{
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	//test_read();
	test_strdup();
	test_atoi_base();
	return (0);
}
