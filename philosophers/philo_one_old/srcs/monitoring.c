#include "philosophers.h"

void *ft_all_done_eating(void *unused)
{
        int i;

        i = 0;
        while (i < NUMBER_OF_PHILOSOPHERS)
                pthread_join(g_philosopher[i++], NULL);
        pthread_mutex_unlock(&g_no_dead_lock);
        return unused;
}

void *ft_all_alive(void *unused)
{
        pthread_mutex_lock(&g_no_dead_lock);
        pthread_mutex_unlock(&g_no_dead_lock);
        return unused;
}

void *ft_countdown(void *id_ptr)
{
        struct timeval  *last_meal;

        last_meal = (struct timeval *)malloc(sizeof *last_meal);
        gettimeofday(last_meal, DST_NONE);
        while (ft_time_elapsed_ms(last_meal) < TIME_TO_DIE)
                msleep(1);
        put_action(*(int*)id_ptr, DYING);
        pthread_mutex_unlock(&g_no_dead_lock);
        return (NULL);
}
