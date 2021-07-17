/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:42:36 by agossuin          #+#    #+#             */
/*   Updated: 2020/10/16 16:42:36 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		main(int argc, char const *argv[])
{
	int		ret;

	if (argc != 5 && argc != 6)
		return (ft_error(ERROR_NB_ARG));
	if ((ret = set_input(argc, argv)))
		return (ret);
	if ((ret = ft_set_data()))
		return (ret);
	pthread_join((*get_data())->all_done_eating, NULL);
	ft_delete_data();
	return (0);
}
