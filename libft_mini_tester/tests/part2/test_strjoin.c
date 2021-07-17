#include "../../mini_libft_tester.h"

int main()
{
	char const *s1 = "HELLO";
	char const *s2 = "YOYOY";

	free(ft_strjoin(s1, s2));
	free(ft_strjoin(NULL, s2));
	free(ft_strjoin(s1, NULL));
	free(ft_strjoin(NULL, NULL));
	return (0);
}