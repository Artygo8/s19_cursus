/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:34:38 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/16 17:34:38 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

size_t	ft_atoi(const char *str)
{
	int		i;
	size_t	value;

	i = 0;
	value = 0;
	while (str[i] >= '0' && str[i] <= '9')
		value = ((value * 10) + (str[i++] - '0'));
	return (value);
}

int		ft_gt_max_ulong(const char *str)
{
	int i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i > ft_strlen(MAX_ULONG))
		return (TRUE);
	else if (i < ft_strlen(MAX_ULONG))
		return (FALSE);
	else if (i == ft_strlen(MAX_ULONG))
	{
		i = 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i] > MAX_ULONG[i])
				return (TRUE);
			i++;
		}
	}
	return (FALSE);
}

int		ft_is_ulong(const char *str)
{
	int i;

	i = 0;
	if (*str == '-')
		return (FALSE);
	while (str[i] == '0')
		i++;
	if (ft_gt_max_ulong(&str[i]))
		return (FALSE);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (TRUE);
	return (FALSE);
}

t_input	*ft_input_dup(int argc, char const *argv[])
{
	t_input	*input;

	if (!ft_is_ulong(argv[1]) || !ft_is_ulong(argv[2])
		|| !ft_is_ulong(argv[3]) || !ft_is_ulong(argv[4])
		|| (argc == 6 && !ft_is_ulong(argv[5])))
	{
		write(2, ERROR_FORMAT, ft_strlen(ERROR_FORMAT));
		return (NULL);
	}
	input = (t_input*)malloc(sizeof(t_input));
	input->nb_philo = ft_atoi(argv[1]);
	input->time_die = ft_atoi(argv[2]);
	input->time_eat = ft_atoi(argv[3]);
	input->time_sleep = ft_atoi(argv[4]);
	input->finite = FALSE;
	if (argc == 6)
	{
		input->finite = TRUE;
		input->nb_must_eat = ft_atoi(argv[5]);
	}
	return (input);
}
