#include <stdio.h>

int ft_strlen(char *s);

int main()
{
	printf("ft_strlen(%s) = %d\n", "", ft_strlen(""));
	printf("ft_strlen(%s) = %d\n", "ab", ft_strlen("ab"));
	printf("ft_strlen(%s) = %d\n", "abc", ft_strlen("abc"));
	printf("ft_strlen(%s) = %d\n", "abcd", ft_strlen("abcd"));
	return 0;
}
