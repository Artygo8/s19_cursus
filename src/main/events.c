/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:47:15 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/22 15:47:16 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	exit_hook(void *p)
{
	ft_free_data(((t_data *)p));
	return (0);
}

int	ft_key(int key, void *p)
{
	if (key == 8)
	{
		if (!((t_data *)p)->cams)
		{
			ft_putstr_fd("No More Cameras\n", 1);
			ft_free_data((t_data *)p);
		}
		else
			ft_show((t_data *)p);
	}
	if (key == 53)
		ft_free_data((t_data *)p);
	return (0);
}

int	ft_events(t_data *data)
{
	mlx_hook(data->mlx_win, 17, 0, exit_hook, (void*)data);
	mlx_key_hook(data->mlx_win, ft_key, (void*)data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
