/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 11:53:02 by vtouffet          #+#    #+#             */
/*   Updated: 2017/11/09 10:44:15 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_b_size(char *base)
{
	int	b_size;
	int	j;

	b_size = 0;
	while (base[b_size])
	{
		if (base[b_size] == '-' || base[b_size] == '+')
			return (0);
		j = b_size + 1;
		while (base[j])
		{
			if (base[b_size] == base[j])
				return (0);
			++j;
		}
		++b_size;
	}
	if (b_size < 2)
		return (0);
	return (b_size);
}

static int	check_errors(char *str, char *base)
{
	int	i;
	int	j;
	int	start;

	start = 0;
	while (str[start] != '\0' && (str[start] == ' ' || str[start] == '\t' ||
		str[start] == '\r' || str[start] == '\n' || str[start] == '\v' ||
		str[start] == '\f'))
		start++;
	i = start;
	while (str[i])
	{
		j = 0;
		while (base[j] && (str[i] != base[j] ||
				(str[i] == '-' || str[i] == '+')))
			j++;
		if (str[i] != base[j] && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

static int	get_nb(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int			ft_atoi_base_c(char *str, char *base)
{
	int	i;
	int	res;
	int	sign;
	int	b_size;

	if (!(b_size = get_b_size(base)) || !check_errors(str, base))
		return (0);
	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f'))
		i++;
	i--;
	res = 0;
	sign = 1;
	while (str[++i] && (((str[i] == '-' || str[i] == '+')) ||
			(str[i] != '-' && str[i] != '+')))
	{
		if (str[i] == '-')
			sign = -1;
		else if (str[i] != '+')
			res = (res * b_size) + (get_nb(str[i], base));
	}
	return (res * sign);
}
