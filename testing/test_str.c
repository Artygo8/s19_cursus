#include "test.h"

int	test_strlen(void)
{
	printf("\n--- test strlen VS ft_strlen ---\n\n");
	printf("ft_strlen(%s) = %lu\n", "", ft_strlen(""));
	printf("strlen(%s) = %lu\n\n", "", strlen(""));
	printf("ft_strlen(%s) = %lu\n", "ab", ft_strlen("ab"));
	printf("strlen(%s) = %lu\n\n", "ab", strlen("ab"));
	printf("ft_strlen(%s) = %lu\n", "abc", ft_strlen("abc"));
	printf("strlen(%s) = %lu\n\n", "abc", strlen("abc"));
	printf("ft_strlen(%s) = %lu\n", "abcd", ft_strlen("abcd"));
	printf("strlen(%s) = %lu\n\n", "abcd", strlen("abcd"));
	return (1);
}

int	test_strcpy(void)
{
	char	dst[12];
	char	dst2[12];

	strcpy(dst, "destination");
	strcpy(dst2, "destination");
	printf("\n--- test strcpy VS ft_strcpy ---\n\n");
	printf("initialization :\n");
	printf("dst = %s\tsrc = %s\n\n", dst, "source");
	printf("strcpy(dst, src) = %s :\n", strcpy(dst, "source"));
	printf("dst = %s\tsrc = %s\n\n", dst, "source");
	printf("ft_strcpy(dst, src) = %s :\n", ft_strcpy(dst2, "source"));
	printf("dst = %s\tsrc = %s\n\n", dst2, "source");
	return (1);
}

int	test_strcmp(void)
{
	printf("\n--- test strcmp VS ft_strcmp ---\n\n");
	printf("strcmp(\"a\", \"c\") = %d\n", strcmp("a", "c"));
	printf("ft_strcmp(\"a\", \"c\") = %d\n", ft_strcmp("a", "c"));
	printf("strcmp(\"aa\", \"ab\") = %d\n", strcmp("aa", "ab"));
	printf("ft_strcmp(\"aa\", \"ab\") = %d\n", ft_strcmp("aa", "ab"));
	printf("strcmp(\"aaa\", \"aab\") = %d\n", strcmp("aaa", "aab"));
	printf("ft_strcmp(\"aaa\", \"aab\") = %d\n", ft_strcmp("aaa", "aab"));
	printf("strcmp(\"aaaa\", \"aaab\") = %d\n", strcmp("aaaa", "aaab"));
	printf("ft_strcmp(\"aaaa\", \"aaab\") = %d\n", ft_strcmp("aaaa", "aaab"));
	printf("strcmp(\"b\", \"a\") = %d\n", strcmp("ba", "aa"));
	printf("ft_strcmp(\"b\", \"a\") = %d\n", ft_strcmp("ba", "aa"));
	printf("strcmp(\"A\", \"a\") = %d\n", strcmp("A", "a"));
	printf("ft_strcmp(\"A\", \"a\") = %d\n", ft_strcmp("A", "a"));
	printf("strcmp(\"\", \"\") = %d\n", strcmp("", ""));
	printf("ft_strcmp(\"\", \"\") = %d\n", ft_strcmp("", ""));
	printf("strcmp(\"A\", \"A\") = %d\n", strcmp("A", "A"));
	printf("ft_strcmp(\"A\", \"A\") = %d\n", ft_strcmp("A", "A"));
	printf("strcmp(\"AB\", \"A\") = %d\n", strcmp("AB\0", "A\0"));
	printf("ft_strcmp(\"AB\", \"A\") = %d\n", ft_strcmp("AB\0", "A\0"));
	printf("strcmp(\"AB\", \"ABC\") = %d\n", strcmp("AB\0", "ABC\0"));
	printf("ft_strcmp(\"AB\", \"ABC\") = %d\n", ft_strcmp("AB\0", "ABC\0"));
	return (1);
}

int	test_strdup(void)
{
	char	*s;

	printf("\n--- test strdup VS ft_strdup ---\n\n");
	s = strdup("hello world!");
	printf("strdup : %s\n", s);
	free(s);
	s = ft_strdup("HELLO WORLD!\0");
	printf("ft_strdup : %s\n", s);
	free(s);
	return (1);
}
