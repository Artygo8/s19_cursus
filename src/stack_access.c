#include "push_swap.h"

t_stack *get_bot_stack(t_stack* stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return stack;
}

t_stack *get_pre_bot_stack(t_stack* stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return stack;
}
