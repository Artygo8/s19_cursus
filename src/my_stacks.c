#include "push_swap.h"

/*
 * Returns the address over one of my 2 stacks.
 * Stack A is id 0.
 */

t_stack	**get_my_stacks(int id)
{
	static t_stack *stackA = NULL;
	static t_stack *stackB = NULL;

	if (id == 0)
		return &stackA;
	else
		return &stackB;
}

void	my_stacks_delete()
{
	delete_stack(get_my_stacks(0));
	delete_stack(get_my_stacks(1));
}

int		my_stacks_is_perfect()
{
	return (disorder_stack(*get_my_stacks(0)) == 0 && *get_my_stacks(1) == NULL);
}

int		my_stacks_is_ordered()
{
	return (disorder_stack(*get_my_stacks(0)) == 0 && 
	disorder_reverse_stack(*get_my_stacks(1)) == 0);
}

void	my_stacks_show()
{
	ft_putstr_fd("Stack A\n -> ", STDOUT_FILENO);
	show_stack(*get_my_stacks(0));
	ft_putstr_fd("Stack B\n -> ", STDOUT_FILENO);
	show_stack(*get_my_stacks(1));
}

/////////////
// ACTIONS //
/////////////

void	gtfo(const char *status)
{
	ft_putendl_fd((char*)status, STDERR_FILENO);
	my_stacks_delete();
	exit(0);
}

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

int		my_stacks_check_rot()
{
	int result;

	result = 0;
	if (disorder_stack(*get_my_stacks(0)) == 1 && (*get_my_stacks(0))->value >
			get_bot_stack(*get_my_stacks(0))->value)
	{
		if (stack_len(*get_my_stacks(0)) / 2 > stack_max_value_index(*get_my_stacks(0)))
			result |= RA;
		else
			result |= RRA;
	}
	if (disorder_reverse_stack(*get_my_stacks(1)) == 1 && (*get_my_stacks(1))->value <
			get_bot_stack(*get_my_stacks(1))->value)
	{
		if (stack_len(*get_my_stacks(1)) / 2 > stack_max_value_index(*get_my_stacks(1)))
			result |= RB;
		else
			result |= RRB;
	}
	return result;
}

int		my_stacks_check_swap()
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
	return result;
}

int		my_stacks_check_push()
{
	if ((*get_my_stacks(1) && disorder_stack(*get_my_stacks(0)) <= disorder_reverse_stack(*get_my_stacks(1))) || !*get_my_stacks(0))
		return PA;
	else
		return PB;
}

void	my_stacks_algo()
{
	// check if its already a rot --> disorder == 1
	// push 2 on the right pile
	// ss or sa by comparing the 4 stuffs on the tops
	// push 'till its good
	int result;

	result = my_stacks_check_rot();
	if (result)
		return my_stacks_apply_and_put(result);
	// if (!(*get_my_stacks(1) && (*get_my_stacks(1))->next) && *get_my_stacks(0))
	//     return my_stacks_apply_and_put(PB);
	result = my_stacks_check_swap();
	if (result)
		return my_stacks_apply_and_put(result);
	return my_stacks_apply_and_put(my_stacks_check_push());
}
