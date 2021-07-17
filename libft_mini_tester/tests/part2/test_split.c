#include "../../mini_libft_tester.h"

int main()
{
	char **test;
	char const *s1 = "HELLO";
	char c = 0;
	int n = 0;

	test = ft_split(s1, c);
	while (test && test[n])
		free(test[n++]);
	free(test);
	test = ft_split(s1, 0);
	while (test && test[n])
		free(test[n++]);
	free(test);
	test = ft_split("", c);
	while (test && test[n])
		free(test[n++]);
	free(test);
	test = ft_split("aaaaaaa", 'a');
	while (test && test[n])
		free(test[n++]);
	free(test);
    return (0);
}