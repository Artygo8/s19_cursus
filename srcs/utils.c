#include "philosophers.h"

#define INT_MIN -2147483648
#define USEC_PER_SEC 1000000
#define MINIMUM_FIELD_WIDTH 12

int   ft_strlen(const char *str)
{
  int i;
  while (str[i])
    i++;
  return (i);
}

int 	ft_putnbr(int n)
{
    int count;

    count = 1;
    if (n < 0 && (n = -n) && (count += 1))
		write(1, "-", 1);
    if (n == INT_MIN && (n = 147483648) && (count += 1))
		write(1, "2", 1);
    if (n / 10)
		count += ft_putnbr(n / 10);
    n = n % 10 + '0';
	write(1, &n, 1);
    return (count);
}

void    ft_put_timestamp(int id, const char *arg)
{
    struct timeval  *current_tv;
    int             mfw;

    pthread_mutex_lock(&g_write_lock);
    current_tv = (struct timeval *)malloc(sizeof *current_tv);
    mfw = MINIMUM_FIELD_WIDTH;
    gettimeofday(current_tv, DST_NONE);

    if (g_start->tv_usec > current_tv->tv_usec) // is it really useful ?
    {
        current_tv->tv_sec -= 1;
        current_tv->tv_usec += USEC_PER_SEC;
    }

    mfw -= ft_putnbr(current_tv->tv_sec - g_start->tv_sec);
    write(1, ".", 1);
    mfw -= ft_putnbr(current_tv->tv_usec - g_start->tv_usec);
    while (mfw-- > 0)
        write(1, " ", 1);
    
    write(1, "- philosopher ", 14);
    ft_putnbr(id);
    
    write(1, " ", 1);
    write(1, arg, ft_strlen(arg));
    write(1, "\n", 1);
    free(current_tv);
    pthread_mutex_unlock(&g_write_lock);
}
