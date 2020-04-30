/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 15:49:43 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/29 10:35:18 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <ctime>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <string>

class Brain {

private:

	void	*adress;

public:

	Brain();
	~Brain();
	void *identify();

};

#endif
