/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 00:00:23 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 00:00:23 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Coplien's form //////////////////////////////////////////////////////////////

Character::Character(std::string name) : name(name)
{
	inv[0] = NULL;
	inv[1] = NULL;
	inv[2] = NULL;
	inv[3] = NULL;
}

Character::Character(const Character &source)
{
	this->name = source.name;
	this->inv[0] = (source.inv[0]) ? source.inv[0]->clone() : 0;
	this->inv[1] = (source.inv[1]) ? source.inv[1]->clone() : 0;
	this->inv[2] = (source.inv[2]) ? source.inv[2]->clone() : 0;
	this->inv[3] = (source.inv[3]) ? source.inv[3]->clone() : 0;
}

Character& Character::operator = (const Character &source)
{
	*this = source;
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete (inv[i]);
		inv[i] = NULL;
	}
}

// others //////////////////////////////////////////////////////////////////////

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inv[i] == NULL)
		{
			inv[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 4 && inv[idx])
	{
		delete inv[idx];
		inv[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && inv[idx])
		(inv[idx])->use(target);
}
