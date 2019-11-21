#include "ft_printf.h"

int		int_size_base(long long n, int base_size)
{
	int		size;

	size = 1;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n >= base_size)
	{
		n /= base_size;
		size++;
	}
	return (size);
}

char	*ft_utoa_base(unsigned int n, char *base)
{
	unsigned int	base_size;
	int				int_size;
	char			*new;
	int				i;

	i = 0;
	base_size = ft_strlen(base);
	int_size = int_size_base(n, base_size);
	if (!(new = malloc(int_size * sizeof(char))))
		return (NULL);
	while (n >= base_size)
	{
		new[int_size - i - 1] = (*base + (n % base_size));
		n /= base_size;
		i++;
	}
	new[int_size - i - 1] = (*base + (n % base_size));
	return (new);
}
