/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:46:29 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/07 17:46:31 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_mat	ft_init_mat(t_vect pos, double dist, int color)
{
	t_mat mat;

	mat.id = 0;
	mat.pos = pos;
	mat.norm = ft_v_init(0, 0, 0);
	mat.dist = dist;
	mat.color = color;
	mat.pxl = 0;
	return (mat);
}
