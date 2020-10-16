#include "../philosophers.h"

int     ft_time_elapsed_ms(struct timeval *origin_tv)
{
        struct timeval  *current_tv;
        int time_elapsed_ms;

        current_tv = (struct timeval *)malloc(sizeof *current_tv);
        gettimeofday(current_tv, DST_NONE);

        time_elapsed_ms = (current_tv->tv_sec - origin_tv->tv_sec) * 1000
                          + (current_tv->tv_usec - origin_tv->tv_usec) / 1000;

        free(current_tv);
        return (time_elapsed_ms);
}

void msleep(int time)
{
        usleep(time * 1000);
}
