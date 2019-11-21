/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:33:00 by agossuin          #+#    #+#             */
/*   Updated: 2019/10/15 10:56:09 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int		ft_printf(const char * format, ...)
{
	va_list ap;
	int i = 0;
	char *s;

	va_start(ap, format);
	while (va_arg(ap+1, char*))
	{
		s = va_arg(ap, char*);
		printf("%s\n", s);
	}
	va_end(ap);
	return 0;
}

int main()
{
	ft_printf("format", "here", "I", "am");
	return (0);
}
