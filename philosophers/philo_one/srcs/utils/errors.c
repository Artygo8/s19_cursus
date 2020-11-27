#include "philosophers.h"

/*
** This function prints an error message and returns NULL.
*/

int     ft_error(int e_error)
{
    if (e_error == ERROR_NB_ARG)
        ft_putstr_fd("Error: wrong number of arguments.\n", STDERR_FILENO);
    else if (e_error == ERROR_NOT_ULONG)
        ft_putstr_fd("Error: argument not unsigned longs.\n", STDERR_FILENO);
    return (e_error);
}