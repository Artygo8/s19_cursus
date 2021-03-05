/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stacks_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:56:30 by agossuin          #+#    #+#             */
/*   Updated: 2021/03/05 10:56:30 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Returns the address over one of my 2 stacks.
** Stack A is id 0.
*/

t_stack	**get_my_stacks(int id)
{
	static t_stack *stack_a = NULL;
	static t_stack *stack_b = NULL;

	if (id == 0)
		return (&stack_a);
	else
		return (&stack_b);
}

void	my_stacks_delete(void)
{
	delete_stack(get_my_stacks(0));
	delete_stack(get_my_stacks(1));
}

int		my_stacks_is_perfect(void)
{
	return (disorder_stack(*get_my_stacks(0)) == 0 &&
								*get_my_stacks(1) == NULL);
}

int		my_stacks_is_ordered(void)
{
	return (disorder_stack(*get_my_stacks(0)) == 0 &&
			disorder_reverse_stack(*get_my_stacks(1)) == 0);
}

void	my_stacks_show(void)
{
	ft_putstr_fd("Stack A\n -> ", STDOUT_FILENO);
	show_stack(*get_my_stacks(0));
	ft_putstr_fd("Stack B\n -> ", STDOUT_FILENO);
	show_stack(*get_my_stacks(1));
}
