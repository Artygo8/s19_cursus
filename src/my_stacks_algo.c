/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stacks_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:56:30 by agossuin          #+#    #+#             */
/*   Updated: 2021/03/05 10:56:30 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		my_stacks_check_rot(void)
{
	int result;

	result = 0;
	if (disorder_stack(*get_my_stacks(0)) == 1 && (*get_my_stacks(0))->value >
			get_bot_stack(*get_my_stacks(0))->value)
	{
		if (stack_len(*get_my_stacks(0)) / 2 >
									stack_max_value_index(*get_my_stacks(0)))
			result |= RA;
		else
			result |= RRA;
	}
	if (disorder_reverse_stack(*get_my_stacks(1)) == 1 &&
		(*get_my_stacks(1))->value < get_bot_stack(*get_my_stacks(1))->value)
	{
		if (stack_len(*get_my_stacks(1)) / 2 >
									stack_max_value_index(*get_my_stacks(1)))
			result |= RB;
		else
			result |= RRB;
	}
	return (result);
}

int		my_stacks_check_swap(void)
{
	int result;

	result = 0;
	if (*get_my_stacks(0) && (*get_my_stacks(0))->next)
	{
		if ((*get_my_stacks(0))->value > (*get_my_stacks(0))->next->value)
			result |= SA;
	}
	if (*get_my_stacks(1) && (*get_my_stacks(1))->next)
	{
		if ((*get_my_stacks(1))->value < (*get_my_stacks(1))->next->value)
			result |= SB;
	}
	return (result);
}

int		my_stacks_check_push(void)
{
	if ((*get_my_stacks(1) && disorder_stack(*get_my_stacks(0)) <=
			disorder_reverse_stack(*get_my_stacks(1))) || !*get_my_stacks(0))
		return (PA);
	else
		return (PB);
}

void	my_stacks_algo(void)
{
	int result;

	result = my_stacks_check_rot();
	if (result)
		return (my_stacks_apply_and_put(result));
	result = my_stacks_check_swap();
	if (result)
		return (my_stacks_apply_and_put(result));
	return (my_stacks_apply_and_put(my_stacks_check_push()));
}
