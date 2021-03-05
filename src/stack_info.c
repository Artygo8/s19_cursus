#include "push_swap.h"

size_t     disorder_stack(t_stack* stack)
{
	int n;
	size_t dis;

	dis = 0;
	while (stack && stack->next)
	{
		n = stack->value;
		stack = stack->next;
		if (n > stack->value)
			++dis;
	}
	return (dis);
}

size_t     disorder_reverse_stack(t_stack* stack)
{
	int n;
	size_t dis;

	dis = 0;
	while (stack && stack->next)
	{
		n = stack->value;
		stack = stack->next;
		if (n < stack->value)
			++dis;
	}
	return (dis);
}

size_t stack_len(t_stack* stack)
{
	size_t  i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		++i;
	}
	return i;
}

size_t     stack_max_value_index(t_stack* stack)
{
	size_t  i;
	size_t  max_index;
	int     max_value;

	i = 0;
	max_index = 0;
	max_value = INT32_MIN;
	while (stack)
	{
		if (stack->value > max_value)
		{
			max_index = i;
			max_value = stack->value;
		}
		stack = stack->next;
		++i;
	}
	return max_index;
}
