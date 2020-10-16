/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:51:40 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/16 16:51:40 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int		ft_time_elapsed_ms(struct timeval *origin_tv)
{
	struct timeval	*current_tv;
	int				time_elapsed_ms;

	current_tv = (struct timeval *)malloc(sizeof(*current_tv));
	gettimeofday(current_tv, NULL);
	time_elapsed_ms = (current_tv->tv_sec - origin_tv->tv_sec) * 1000
		+ (current_tv->tv_usec - origin_tv->tv_usec) / 1000;
	free(current_tv);
	return (time_elapsed_ms);
}

void	ft_put_abs_time(struct timeval *origin_tv)
{
	struct timeval	*current_tv;
	int				time_elapsed_ms;

	current_tv = (struct timeval *)malloc(sizeof(*current_tv));
	gettimeofday(current_tv, NULL);
	ft_putnbr(current_tv->tv_sec);
	if (current_tv->tv_usec / 1000 < 100)
		ft_putnbr(0);
	if (current_tv->tv_usec / 1000 < 10)
		ft_putnbr(0);
	ft_putnbr(current_tv->tv_usec / 1000);
	free(current_tv);
}

t_tv	*ft_timedup(void)
{
	t_tv	*new_tv;

	new_tv = (struct timeval *)malloc(sizeof(t_tv));
	gettimeofday(new_tv, NULL);
	return (new_tv);
}

void	msleep(int time)
{
	usleep(time * 1000);
}
