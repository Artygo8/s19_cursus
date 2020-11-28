/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:34:38 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/16 17:34:38 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*ft_get_mutex(int e_mutex)
{
	static pthread_mutex_t	datas[SIZE_MUTEX];

	return (&(datas[e_mutex]));
}

void			ft_init_mutex(void)
{
	pthread_mutex_init(ft_get_mutex(NO_DEADS), NULL);
	pthread_mutex_init(ft_get_mutex(WRITE), NULL);
	pthread_mutex_init(ft_get_mutex(BINARY1), NULL);
	pthread_mutex_init(ft_get_mutex(BINARY2), NULL);
}