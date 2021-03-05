/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:56:30 by agossuin          #+#    #+#             */
/*   Updated: 2021/03/05 10:56:30 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int index;

	index = argc;
	while (index > 1)
	{
		if (!is_int(argv[--index]) ||
				is_in_stack(*get_my_stacks(0), ft_atoi(argv[index])))
			gtfo("Error");
		push_stack(get_my_stacks(0), ft_atoi(argv[index]));
	}
	while (!my_stacks_is_perfect())
	{
		my_stacks_algo();
	}
}
