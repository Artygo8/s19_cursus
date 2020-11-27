/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:34:38 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/16 17:34:38 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int		*get_input(int e_input)
{
	static	int input[SIZE_INPUTS];

	return &(input[e_input]);
}

int		set_input(int argc, char const *argv[])
{
	size_t	index;

	index = argc - 1;
	while (index > 0)
	{
		if (!ft_is_ulong(argv[index--]))
			return (ft_error(ERROR_NOT_ULONG));
	}
	*get_input(NB_PHILO) = ft_atoi(argv[1]);
	*get_input(TIME_TO_DIE) = ft_atoi(argv[2]);
	*get_input(TIME_TO_EAT) = ft_atoi(argv[3]);
	*get_input(TIME_TO_SLEEP) = ft_atoi(argv[4]);
	if (argc == 6)
	{
		*get_input(IS_FINITE) = TRUE;
		*get_input(NB_MUST_EAT) = ft_atoi(argv[5]);
	}
	return (0);
}
