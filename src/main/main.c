/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:45:55 by agossuin          #+#    #+#             */
/*   Updated: 2020/01/07 17:45:57 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	ft_explain(char *str)
{
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_data *data;

	if (!(argc == 2 || argc == 3))
		return (ft_explain("WRONG NUMBER OF ARGUMENTS"));
	if (!(data = ft_data((char*)argv[1])))
		return (ft_explain("PARSING ERROR"));
	if (argc == 2)
	{
		ft_show(data);
		ft_events(data);
		ft_free_data(data, "End Of Program");
	}
	if (argc == 3 && !ft_strncmp((char*)argv[2], "-save", 6))
	{
		ft_bmp(data, (char*)argv[1]);
	}
	return (0);
}
