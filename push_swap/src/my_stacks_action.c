/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stacks_action.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:56:30 by agossuin          #+#    #+#             */
/*   Updated: 2021/03/05 10:56:30 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	my_stacks_action(int id)
{
	if (id & SA)
		swap_stack(get_my_stacks(0));
	if (id & SB)
		swap_stack(get_my_stacks(1));
	if (id & PA)
		push_from_stack(get_my_stacks(1), get_my_stacks(0));
	if (id & PB)
		push_from_stack(get_my_stacks(0), get_my_stacks(1));
	if (id & RA)
		rotate_stack(get_my_stacks(0));
	if (id & RB)
		rotate_stack(get_my_stacks(1));
	if (id & RRA)
		rotate_reverse_stack(get_my_stacks(0));
	if (id & RRB)
		rotate_reverse_stack(get_my_stacks(1));
}

void	my_stacks_put_action(int id)
{
	if (id == SA)
		ft_putendl_fd("sa", 1);
	if (id == SB)
		ft_putendl_fd("sb", 1);
	if (id == SS)
		ft_putendl_fd("ss", 1);
	if (id == PA)
		ft_putendl_fd("pa", 1);
	if (id == PB)
		ft_putendl_fd("pb", 1);
	if (id == RA)
		ft_putendl_fd("ra", 1);
	if (id == RB)
		ft_putendl_fd("rb", 1);
	if (id == RR)
		ft_putendl_fd("rr", 1);
	if (id == RRA)
		ft_putendl_fd("rra", 1);
	if (id == RRB)
		ft_putendl_fd("rrb", 1);
	if (id == RRR)
		ft_putendl_fd("rrr", 1);
}

void	my_stacks_apply_and_put(int action)
{
	my_stacks_put_action(action);
	my_stacks_action(action);
}
