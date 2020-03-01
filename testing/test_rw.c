#include "test.h"

int test_write(void)
{
	printf("\n--- test write VS ft_write ---\n\n");
	printf("write :\n");
	printf("\nvalue = %zd\n", write(1, "Hello World!", 12));
	printf("\nvalue = %zd\n", write(1, "Hello World!", 5));
	printf("ft_write :\n");
	printf("\nvalue = %zd\n", ft_write(1, "Hello World!", 12));
	printf("\nvalue = %zd\n", ft_write(1, "Hello World!", 5));
	return (1);
}

int	test_read(void)
{
	int		ret;
	char	buf[1024];

	printf("\n--- test read VS ft_read ---\n\n");
	printf("WRITE SOMETHING\n");
	ret = read(1, buf, sizeof(buf)-1);
	buf[ret] = 0;
	printf("READ RESULT: %s", buf);
	printf("WRITE SOMETHING AGAIN\n");
	ret = ft_read(1, buf, sizeof(buf)-1);
	buf[ret] = 0;
	printf("FT_READ RESULT: %s", buf);
	return (1);
}
