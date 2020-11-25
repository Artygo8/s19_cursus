#include "../../mini_libft_tester.h"

int main()
{
    char const *s1 = "HELLO";
	unsigned int start = 0;
	size_t len = 5;

	free(ft_substr(s1, start, len));
	free(ft_substr(NULL, start, len));
	free(ft_substr(0, start, len));
	free(ft_substr(s1, 1, 1));
	free(ft_substr(s1, -1, 545));
	free(ft_substr(s1, 5, -1));
	free(ft_substr(s1, 5, 5));
	free(ft_substr(s1, 6, 6));
    return (0);
}
