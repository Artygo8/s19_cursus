#include "push_swap.h"

static void	apply_on_stacks(const char *line)
{
	if (!ft_strncmp(line, "sa", 3))
		return my_stacks_action(SA);
	if (!ft_strncmp(line, "sb", 3))
		return my_stacks_action(SB);
	if (!ft_strncmp(line, "ss", 3))
		return my_stacks_action(SS);
	if (!ft_strncmp(line, "pa", 3))
		return my_stacks_action(PA);
	if (!ft_strncmp(line, "pb", 3))
		return my_stacks_action(PB);
	if (!ft_strncmp(line, "ra", 3))
		return my_stacks_action(RA);
	if (!ft_strncmp(line, "rb", 3))
		return my_stacks_action(RB);
	if (!ft_strncmp(line, "rr", 3))
		return my_stacks_action(RR);
	if (!ft_strncmp(line, "rra", 4))
		return my_stacks_action(RRA);
	if (!ft_strncmp(line, "rrb", 4))
		return my_stacks_action(RRB);
	if (!ft_strncmp(line, "rrr", 4))
		return my_stacks_action(RRR);
	gtfo("Error");
}

int			main(int argc, char *argv[])
{
	int index;
	char *line;

	index = argc;
	while (index > 1)
	{
		// check the quality of the input.
		push_stack(get_my_stacks(0), ft_atoi(argv[--index]));
	}
	while (get_next_line(STDIN_FILENO, &line) > 0 && !my_stacks_is_perfect())
	{
		apply_on_stacks(line);
		free(line);
	}
	free(line);
	my_stacks_delete();
	ft_putstr_fd("OK\n", STDOUT_FILENO);
	return 0;
}
