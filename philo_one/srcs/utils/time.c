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

ssize_t		ft_time_elapsed_ms(ssize_t origin_ms)
{
	ssize_t		current_ms;

	if ((current_ms = ft_get_ms()) == -1)
		return (-1);
	return (current_ms - origin_ms);
}

ssize_t		ft_put_abs_time(void)
{
	ssize_t		current_ms;

	if ((current_ms = ft_time_elapsed_ms(*get_input(START))) == -1)
		return (-1);
	ft_putunbr(current_ms);
	return (0);
}

ssize_t		ft_get_ms(void)
{
	t_tv	tv_time;
	size_t	ms_time;

	if (gettimeofday(&tv_time, NULL) == -1)
	{
		ft_error(ERROR_GTOD);
		return (-1);
	}
	ms_time = tv_time.tv_sec * 1000 + tv_time.tv_usec / 1000;
	return (ms_time);
}

void		msleep(ssize_t time)
{
	ssize_t end;

	end = ft_get_ms() + time;
	while (ft_get_ms() < end)
		usleep(400);
}
