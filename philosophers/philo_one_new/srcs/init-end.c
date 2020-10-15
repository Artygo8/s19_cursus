#include "philosophers.h"

// int     *ids_initializer(void)
// {
//         int *ids;
//         int i;
//
//         ids = (int*)malloc(NUMBER_OF_PHILOSOPHERS * sizeof ids);
//         i = -1;
//         while (++i < NUMBER_OF_PHILOSOPHERS)
//                 ids[i] = i + 1;
//         return ids;
// }


// void mutex_initializer(void)
// {
//         int i;
//
//         i = 0;
//         while (i < NUMBER_OF_PHILOSOPHERS)
//                 pthread_mutex_init(&g_forks[i++], NULL);
//         pthread_mutex_init(&g_write_lock, NULL);
//         pthread_mutex_init(&g_binary_lock[0], NULL);
//         pthread_mutex_init(&g_binary_lock[1], NULL);
//         pthread_mutex_init(&g_no_dead_lock, NULL);
// }
//
// void mutex_destroyer(void)
// {
//         int i;
//
//         i = 0;
//         while (i < NUMBER_OF_PHILOSOPHERS)
//                 pthread_mutex_destroy(&g_forks[i++]);
//         pthread_mutex_destroy(&g_write_lock);
//         pthread_mutex_destroy(&g_binary_lock[0]);
//         pthread_mutex_destroy(&g_binary_lock[1]);
//         pthread_mutex_destroy(&g_no_dead_lock);
// }
