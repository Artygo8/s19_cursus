#include "philosophers.h"

void *ft_all_done_eating(void *vars_ptr)
{
	int i;
	t_vars	*vars;

	i = 0;
	vars = (t_vars)(*vars_ptr);
	while ((vars->table)[i])
		pthread_join(((vars->table)[i++]).live, NULL);
	pthread_mutex_unlock(&(vars->no_dead_lock));
	return NULL;
}

void *ft_all_alive(void *vars_ptr)
{
	t_vars	*vars;

	vars = (t_vars)(*vars_ptr);
	pthread_mutex_lock(&(vars->no_dead_lock));
	pthread_mutex_unlock(&(vars->no_dead_lock));
	return NULL;
}

// void *ft_countdown(void *vars_ptr)
// {
// 	int i;
// 	t_vars	*vars;
//
// 	i = 0;
// 	vars = (t_vars)(*vars_ptr);
// 	last_meal = (struct timeval *)malloc(sizeof *last_meal);
// 	gettimeofday(last_meal, DST_NONE);
// 	while (ft_time_elapsed_ms(last_meal) < TIME_TO_DIE)
// 		msleep(1);
// 	put_action(*(int*)id_ptr, DYING);
// 	pthread_mutex_unlock(&g_no_dead_lock);
// 	return (NULL);
// }
