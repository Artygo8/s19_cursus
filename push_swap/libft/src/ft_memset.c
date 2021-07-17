/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 09:05:10 by agossuin          #+#    #+#             */
/*   Updated: 2019/10/17 13:18:21 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *b, int n, size_t len)
{
	char	*c;

	c = (char*)b;
	while (len > 0)
		c[--len] = n;
	return (b);
}
