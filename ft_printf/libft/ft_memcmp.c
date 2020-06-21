/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:31:01 by agossuin          #+#    #+#             */
/*   Updated: 2019/10/07 13:31:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)&s1[i] != *(unsigned char*)&s2[i])
			return (*(unsigned char*)&s1[i] - *(unsigned char*)&s2[i]);
		i++;
	}
	return (0);
}
