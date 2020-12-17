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

Enemy::Enemy(int hp, std::string const & type) : hp(hp) , type(type) {}

Enemy::Enemy(const Enemy &source) : Enemy(source.hp, source.type) {}

Enemy::~Enemy() {}

Enemy& Enemy::operator = (const Enemy &source)
{
	this->type = source.type;
	this->hp = source.hp;
	return *this;
}

// set-get ////////////////////////////////////////////////////////////////////

std::string const Enemy::getType() const
{
	return type;
}

int Enemy::getHP() const
{
	return hp;
}

void Enemy::takeDamage(int amount)
{
	if (amount >= 0)
	{
		this->hp -= amount;
		std::cout << this->type << " takes " << amount << " damages" << std::endl;
		if (this->hp < 0) this->hp = 0;
	}
}

std::ostream &operator<<(std::ostream &out, Enemy const &obj)
{
	return out << RED << obj.getType() << " has " << obj.getHP() << " hp" << NC << std::endl;
}
