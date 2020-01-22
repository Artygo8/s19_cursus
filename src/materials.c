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

t_mat	ft_init_mat(t_vect pos)
{
	t_mat mat;

	mat.id = 0;
	mat.pos = pos;
	mat.norm = (t_vect){0, 0, 0};
	mat.dist = INFINITY;
	mat.color = 0;
	mat.pxl = BACKGROUND;
	return (mat);
}
