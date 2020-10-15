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

t_tv	*ft_timedup(void)
{
	t_tv	*new_tv;

	new_tv = (struct timeval *)malloc(sizeof g_start_tv);
	gettimeofday(new_tv, DST_NONE);
	return (new_tv);
}

void msleep(int time)
{
        usleep(time * 1000);
}
