#include "../libft/libft.h"
#include <stdio.h>

int main()
{
	char const *s1 = "HELLO";
	char const *s2 = "YOYOY";
	char *s = "NULLO";
	unsigned int start = 0;
	size_t len = 5;
	int n = 0;
	char c = 0;
	char **test;
	char *yo;

	printf("\e[1;37m__FT_LSTADD_FRONT__\n");
	ft_lstadd_front(NULL, NULL);
	printf("\e[32mAll good !\n\n\e[1;37m");

	printf("__FT_LSTADD_BACK__\n");
	ft_lstadd_back(NULL, NULL);
	printf("\e[32mAll good !\n\n\e[1;37m");

	printf("__FT_LSTCLEAR__\n");
	ft_lstclear(NULL, NULL);
	printf("\e[32mAll good !\n\n\e[1;37m");

	printf("__FT_LSTDELONE__\n");
	ft_lstdelone(NULL, NULL);
	printf("\e[32mAll good !\n\n\e[1;37m");

	printf("__FT_LSTITER__\n");
	ft_lstiter(NULL, NULL);
	printf("\e[32mAll good !\n\n\e[1;37m");

	printf("__FT_LSTSIZE__\n");
	ft_lstsize(NULL);
	printf("\e[32mAll good !\n\n\e[1;37m");

	printf("__FT_LSTLAST__\n");
	free(ft_lstlast(NULL));
	printf("\e[32mAll good !\n\n\e[1;37m");

	printf("__FT_LSTNEW__\n");
	free(ft_lstnew(NULL));
	printf("\e[32mAll good !\n\n\e[1;37m");

	printf("__FT_LSTMAP__\n");
	free(ft_lstmap(NULL, NULL, NULL));
	printf("\e[32mAll good !\n\n\e[1;37m");

	return 0;
}
