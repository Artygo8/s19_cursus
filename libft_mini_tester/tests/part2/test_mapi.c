#include "../../mini_libft_tester.h"

int main()
{
	char const *s1 = "HELLO";

	free(ft_strmapi(s1, NULL));
	free(ft_strmapi(NULL, NULL));
    return (0);
}