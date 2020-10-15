#include "../philosophers.h"

#define INT_MIN -2147483648
#define MINIMUM_FIELD_WIDTH 12

int		ft_strlen(const char *str)
{
        int i;

        i = 0;
        while (str[i] != '\0')
                i++;
        return (i);
}

int		ft_int_width(int n)
{
        int count;

        count = 1;
        while (n / 10)
        {
                n /= 10;
                count += 1;
        }
        return count;
}

void	ft_putnbr(int n)
{
        if (n < 0 && (n = -n))
                write(1, "-", 1);
        if (n == INT_MIN && (n = 147483648))
                write(1, "2", 1);
        if (n / 10)
                ft_putnbr(n / 10);
        n = n % 10 + '0';
        write(1, &n, 1);
}

void	put_action(int id, const char *action)
{
        int mfw;
        int time;

        pthread_mutex_lock(&g_write_lock);
        time = ft_time_elapsed_ms(g_start_tv);
        ft_putnbr(time);
        write(1, "ms", 2);
        mfw = ft_int_width(time);
        while (mfw++ < MINIMUM_FIELD_WIDTH)
                write(1, " ", 1);
        ft_putnbr(id);
        write(1, action, ft_strlen(action));
        write(1, "\n", 1);
        pthread_mutex_unlock(&g_write_lock);
}
