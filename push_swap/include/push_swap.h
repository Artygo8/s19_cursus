/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include/push_swap.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:56:30 by agossuin          #+#    #+#             */
/*   Updated: 2021/03/05 10:56:30 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef struct s_stack	t_stack;

struct		s_stack
{
	int		value;
	t_stack	*next;
};

enum		e_actions {
	SA = 0b01,
	SB = 0b10,
	SS = 0b11,
	PA = 0b0100,
	PB = 0b1000,
	RA = 0b010000,
	RB = 0b100000,
	RR = 0b110000,
	RRA = 0b01000000,
	RRB = 0b10000000,
	RRR = 0b11000000
};

/*
** stack_access.c
*/

t_stack		*get_bot_stack(t_stack *stack);
t_stack		*get_pre_bot_stack(t_stack *stack);

/*
** stack_basics.c
*/

t_stack		*new_stack(const int value);
void		push_stack(t_stack **stack_ad, const int value);
void		pop_stack(t_stack **stack_ad);
void		delete_stack(t_stack **stack_ad);
void		show_stack(t_stack *stack);

/*
** stack_info.c
*/

size_t		disorder_stack(t_stack *stack);
size_t		disorder_reverse_stack(t_stack *stack);
size_t		stack_max_value_index(t_stack *stack);
size_t		stack_len(t_stack *stack);
int			is_in_stack(t_stack *stack, int value);

/*
** stack_action.c
*/

void		swap_stack(t_stack **stack_ad);
void		push_from_stack(t_stack **from_ad, t_stack **to_ad);
void		rotate_stack(t_stack **stack_ad);
void		rotate_reverse_stack(t_stack **stack_ad);

/*
** my_stacks.c
*/

t_stack		**get_my_stacks(int id);
void		my_stacks_delete();
int			my_stacks_is_perfect();
int			my_stacks_is_ordered();
void		my_stacks_show();

void		my_stacks_action(int id);
void		my_stacks_algo();

void		my_stacks_put_action(int id);
void		my_stacks_apply_and_put(int action);

/*
** tools.c
*/

void		gtfo(const char *status);
char		**get_line();
int			is_int(const char *arg);

#endif
