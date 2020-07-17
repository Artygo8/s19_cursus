#include "philosophers.h"

void *living(void *id_ptr)
{
    int i;
    int id;

    i = 0;
    id = (int)id_ptr;
    while (i < NUMBER_OF_TIME_EACH_PHILOSOPHER_MUST_EAT)
    {
        // compare the time with last time it ate.
        ft_put_timestamp(id, "is thinking");
        if (id == 5)
        {
            ft_put_timestamp(id, "died");
            return &id;
        }
        pthread_mutex_lock(&g_forks[id]);
        ft_put_timestamp(id, "has taken a fork");
        pthread_mutex_lock(&g_forks[(id + 1) % NUMBER_OF_PHILOSOPHERS]);
        ft_put_timestamp(id, "has taken a fork");
        ft_put_timestamp(id, "is eating");
        usleep(TIME_TO_EAT);
        pthread_mutex_unlock(&g_forks[(id + 1) % NUMBER_OF_PHILOSOPHERS]);
        pthread_mutex_unlock(&g_forks[id]);
        ft_put_timestamp(id, "is sleeping");
        i++;
    }
    return NULL;
}

int main()
{
    pthread_t       philosopher[NUMBER_OF_PHILOSOPHERS];
    int             i;

    g_start = (struct timeval *)malloc(sizeof g_start);
    gettimeofday(g_start, DST_NONE);

    i = 0;
    while (i < NUMBER_OF_PHILOSOPHERS)
        pthread_mutex_init(&g_forks[i++], NULL);
    pthread_mutex_init(&g_write_lock, NULL);

    i = -1;
    while (++i < NUMBER_OF_PHILOSOPHERS)
        pthread_create(&philosopher[i], NULL, living, (void*)i);
    
    i = -1;
    while (++i < NUMBER_OF_PHILOSOPHERS){
        pthread_join(philosopher[i], NULL);
        pthread_detach(philosopher[i]); }       

    i = 0;
    while (i < NUMBER_OF_PHILOSOPHERS)
        pthread_mutex_destroy(&g_forks[i++]);
    pthread_mutex_destroy(&g_write_lock);

    free(g_start);
}