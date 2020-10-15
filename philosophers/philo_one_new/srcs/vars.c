#include "philosophers.h"

void	ft_init_vars(t_vars *vars)
{
	vars->start_tv = ft_timedup();
	pthread_mutex_init(&(vars->no_dead_lock), NULL);
	pthread_mutex_init(&(vars->write_lock), NULL);
	pthread_mutex_init(&(vars->binary_lock[0]), NULL);
	pthread_mutex_init(&(vars->binary_lock[1]), NULL);
	vars->philos = ft_table_dup(vars->nb_philo);
}

void	ft_delete_vars(t_vars *vars)
{
	free(vars->start_tv);
	pthread_mutex_destroy(&(vars->no_dead_lock));
	pthread_mutex_destroy(&(vars->write_lock));
	pthread_mutex_destroy(&(vars->binary_lock[0]));
	pthread_mutex_destroy(&(vars->binary_lock[1]));
	ft_delete_table(vars->table);
}
