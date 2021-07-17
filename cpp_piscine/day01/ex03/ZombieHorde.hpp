/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 14:42:11 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 15:27:25 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP
# include "Zombie.hpp"

typedef std::string string;

class ZombieHorde {

public:

	ZombieHorde(int N);
	~ZombieHorde();

	void	announce();

private:

	int			n;
	Zombie		*zombieHorde;
	std::string	type;
};

#endif
