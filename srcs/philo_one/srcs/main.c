#include "philosophers.h"

void eating(int id, int turn)
{
        pthread_mutex_lock(&g_binary_lock[((id + turn) / 2) % 2]);
        pthread_mutex_lock(&g_forks[id % NUMBER_OF_PHILOSOPHERS]);
        put_action(id, FORKING);
        pthread_mutex_lock(&g_forks[(id + 1) % NUMBER_OF_PHILOSOPHERS]);
        pthread_mutex_unlock(&g_binary_lock[((id + turn) / 2) % 2]);
        put_action(id, FORKING);
        put_action(id, EATING);
}

void *living(void *id_ptr)
{
        int id;
        int turn;
        pthread_t countdown;

        id = *(int*)id_ptr;
        turn = 0;
        pthread_create(&countdown, NULL, ft_countdown, id_ptr);
        while (turn < NUMBER_OF_TIME_EACH_PHILOSOPHER_MUST_EAT)
        {
                put_action(id, THINKING);
                eating(id, turn);
                pthread_detach(countdown);
                msleep(TIME_TO_EAT);
                pthread_create(&countdown, NULL, ft_countdown, id_ptr);
                pthread_mutex_unlock(&g_forks[id % NUMBER_OF_PHILOSOPHERS]);
                pthread_mutex_unlock(&g_forks[(id + 1) % NUMBER_OF_PHILOSOPHERS]);
                put_action(id, SLEEPING);
                msleep(TIME_TO_SLEEP);
                turn++;
        }
        pthread_detach(countdown);
        return NULL;
}

int main()
{
        pthread_t all_alive;
        pthread_t all_done_eating;
        int *ids;
        int i;

        ids = ids_initializer();
        time_initializer();
        mutex_initializer();
        pthread_mutex_lock(&g_no_dead_lock);
        i = -1;
        while (++i < NUMBER_OF_PHILOSOPHERS)
                pthread_create(&(g_philosopher[i]), NULL, living, &ids[i]);
        pthread_create(&all_done_eating, NULL, ft_all_done_eating, NULL);
        pthread_create(&all_alive, NULL, ft_all_alive, NULL);
        pthread_join(all_alive, NULL);
        i = 0;
        while (i < NUMBER_OF_PHILOSOPHERS)
                pthread_detach(g_philosopher[i++]);
        pthread_detach(all_alive);
        pthread_detach(all_done_eating);
        mutex_destroyer();
        free(g_start_tv);
        return 0;
}
