/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:28:15 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 13:40:06 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include "Zombie.hpp"

typedef std::string string;

const std::string		random_name();

class ZombieEvent {

private:

	std::string type;

public:

	ZombieEvent();
	~ZombieEvent();

	void	setZombieType(std::string type);
	Zombie* newZombie(std::string name);
	void	randomChump();

};

#endif
