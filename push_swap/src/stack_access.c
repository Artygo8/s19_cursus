/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:56:30 by agossuin          #+#    #+#             */
/*   Updated: 2021/03/05 10:56:30 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_bot_stack(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*get_pre_bot_stack(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}
