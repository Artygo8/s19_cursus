#include "../../mini_libft_tester.h"

int main()
{
	char const *s1 = "HELLO";

    free(ft_strtrim(s1, "abc"));
	free(ft_strtrim(NULL, "abc"));
	free(ft_strtrim(s1, ""));
	free(ft_strtrim("", ""));
	free(ft_strtrim("", "abc"));
	free(ft_strtrim(s1, NULL));
    return (0);
}