/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:51:40 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/16 16:51:40 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_int_width(int n)
{
	int count;

	count = 1;
	while (n / 10)
	{
		n /= 10;
		count += 1;
	}
	return (count);
}

void	ft_putnbr(size_t n)
{
	if (n / 10)
		ft_putnbr(n / 10);
	n = n % 10 + '0';
	write(1, &n, 1);
}

void	ft_put_action(t_philo *philo, const char *action)
{
	int time;

	pthread_mutex_lock(&(philo->data->write_lock));
	ft_put_abs_time(philo->data->start_tv);
	write(1, " ", 1);
	ft_putnbr(philo->id);
	write(1, action, ft_strlen(action));
	write(1, "\n", 1);
	if (ft_strlen(action) != ft_strlen(DYING))
		pthread_mutex_unlock(&(philo->data->write_lock));
}
