/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

// Coplien /////////////////////////////////////////////////////////////////////

Enemy::Enemy(int hp, std::string const & type) :
hp(hp) , type(type)
{
	// std::cout << "Default constructor for Enemy called" << std::endl;
}

Enemy::Enemy(const Enemy &source) :
hp(source.hp) , type(source.type)
{
	// std::cout << "Copy constructor for Enemy called" << std::endl;
}

Enemy::~Enemy()
{
	// std::cout << "Destructor for Enemy called" << std::endl;
}

Enemy& Enemy::operator = (const Enemy &source)
{
	// std::cout << "Assignations operator for Enemy called" << std::endl;
	this->type = source.type;
	this->hp = source.hp;
	return *this;
}

//

std::string const Enemy::getType() const
{
	return (type);
}

int Enemy::getHP() const
{
	return (hp);
}

void Enemy::takeDamage(int amount)
{
	if (amount >= 0)
	{
		this->hp -= amount;
		std::cout << this->type << " takes " << amount << " damages" << std::endl;
		if (this->hp < 0)
			this->hp = 0;
	}
}

std::ostream &operator<<(std::ostream &out, Enemy const &obj)
{
	out << obj.getType() << " has " << obj.getHP() << " hp" << std::endl;
	return out;
}
