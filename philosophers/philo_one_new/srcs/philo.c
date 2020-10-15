#include "philosophers.h"

// each philos is dupped

t_philo *ft_philo_dup(int id)
{
	t_philo	*new;

	new = (t_philo*)malloc(sizeof(t_philo));
	memset(new, 0, sizeof(new));
	new->id = id;
	new->eat_count = 0;
	// quid threads ?
	new->last_meal = ft_timedup();
	return (new);
}

// NULL terminated table of philosophers.

t_philo	**ft_table_dup(int nb_philo)
{
	int 		id;
	t_philo		**table;

	id = 0;
	table = (t_philo **)malloc((nb_philo + 1) * sizeof(t_philo *));
	memset(table, 0, sizeof(table));
	while (id++ < nb_philo)
		table[id - 1] = ft_philo_dup(id);
	table[id - 1] = NULL;
	return (table);
}


void	ft_delete_table(t_philo **table)
{
	int id;

	id = 0;
	while (table[id])
	{
		free((table[id])->last_meal)
		free(table[id]);
		id++;
	}
	free(table);
}
