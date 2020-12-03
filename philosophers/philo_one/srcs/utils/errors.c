#include "philosophers.h"

int     ft_error(int e_error)
{
    if (e_error == ERROR_NB_ARG)
        ft_putstr_fd("Error: wrong number of arguments.\n", STDERR_FILENO);
    else if (e_error == ERROR_NOT_ULONG)
        ft_putstr_fd("Error: argument not unsigned long.\n", STDERR_FILENO);
    else if (e_error == ERROR_MALLOC_FAIL)
        ft_putstr_fd("Error: malloc fail.\n", STDERR_FILENO);
    return (e_error);
}