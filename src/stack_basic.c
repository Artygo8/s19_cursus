#include "push_swap.h"

t_stack *new_stack(const int value)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	new->value = value;
	new->next = NULL;
	return (new);
}

void    push_stack(t_stack** stack_ad, const int value)
{
	t_stack *first;

	first = new_stack(value);
	first->next = *stack_ad;
	*stack_ad = first;
}

void    pop_stack(t_stack** stack_ad)
{
	t_stack *first;

	if (!*stack_ad) return ;
	first = *stack_ad;
	*stack_ad = (*stack_ad)->next;
	free(first);
}

void    delete_stack(t_stack **stack_ad)
{
	t_stack *next;

	if (!*stack_ad) return ;
	next = (*stack_ad)->next;
	while (next) {
		free(*stack_ad);
		*stack_ad = next;
		next = next->next;
	}
	free(*stack_ad);
	*stack_ad = NULL;
}

void    show_stack(t_stack* stack)
{
	while (stack)
	{
		ft_putnbr_fd(stack->value, STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
		stack = stack->next;
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
}
