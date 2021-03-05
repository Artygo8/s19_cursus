/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:56:30 by agossuin          #+#    #+#             */
/*   Updated: 2021/03/05 10:56:30 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stack_ad)
{
	t_stack *top;
	t_stack *second;

	top = *stack_ad;
	if (!top || !top->next)
		gtfo("KO");
	second = top->next;
	top->next = top->next->next;
	second->next = top;
	*stack_ad = second;
}

void	push_from_stack(t_stack **from_ad, t_stack **to_ad)
{
	t_stack *top;

	top = *from_ad;
	if (!top)
		gtfo("KO");
	*from_ad = top->next;
	top->next = *to_ad;
	*to_ad = top;
}

void	rotate_stack(t_stack **stack_ad)
{
	t_stack *top;
	t_stack *bot;

	if (!*stack_ad)
		return ;
	top = *stack_ad;
	bot = get_bot_stack(*stack_ad);
	*stack_ad = top->next;
	top->next = NULL;
	bot->next = top;
}

void	rotate_reverse_stack(t_stack **stack_ad)
{
	t_stack *bot;
	t_stack *pre_bot;

	if (!*stack_ad)
		return ;
	pre_bot = get_pre_bot_stack(*stack_ad);
	bot = pre_bot->next;
	pre_bot->next = NULL;
	bot->next = *stack_ad;
	*stack_ad = bot;
}
