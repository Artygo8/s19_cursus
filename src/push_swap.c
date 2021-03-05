#include "push_swap.h"

int main(int argc, char *argv[])
{
	int index = argc;

	while (index > 1)
	{
		push_stack(get_my_stacks(0), ft_atoi(argv[--index]));
	}
	while (!my_stacks_is_perfect())
	{
		my_stacks_algo();
	}
}
