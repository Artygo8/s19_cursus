#include "ft_printf.h"

int			ft_atoi_p(const char *str)
{
	int					sign;
	unsigned long int	value;

	sign = 1;
	value = 0;
	while (ft_is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value = ((value * 10) + (*str - 48));
		str++;
	}
	if (value > 2147483648 && value > 9223372036854775807)
		return ((sign == -1) ? 0 : -1);
	return (value * sign);
}
