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

#include "philosophers.h"

int		ft_time_elapsed_ms(size_t origin_ms)
{
	size_t		time_elapsed_ms;

	time_elapsed_ms = ft_get_ms() - origin_ms;
	return (time_elapsed_ms);
}

void	ft_put_abs_time(void)
{
	ft_putunbr(ft_get_ms());
}

size_t	ft_get_ms(void)
{
	t_tv	tv_time;
	size_t	ms_time;

	gettimeofday(&tv_time, NULL);
	ms_time = tv_time.tv_sec * 1000 + tv_time.tv_usec / 1000;
	return (ms_time);
}

void	msleep(int time)
{
	usleep(time * 1000);
}
