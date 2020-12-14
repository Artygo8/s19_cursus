/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Coplien ////////////////////////////////////////////////////////////////////

Character::Character(std::string const &name) : name(name), ap(MAX_AP), wp(NULL)
{
	// std::cout << "Default constructor for Character called" << std::endl;
}

Character::Character(const Character &source) : name(source.name), ap(source.ap), wp(source.wp)
{
	// std::cout << "Copy constructor for Character called" << std::endl;
}

Character::~Character()
{
	// std::cout << "Destructor for Character called" << std::endl;
}

Character & Character::operator = (const Character &source)
{
	// std::cout << "Assignations operator for Character called" << std::endl;
	this->name = source.name;
	this->ap = source.ap;
	this->wp = source.wp;
	return *this;
}

// Utils //////////////////////////////////////////////////////////////////////

void				Character::recoverAP()
{
	ap += 10;
	if (ap > MAX_AP)
		ap = MAX_AP;
}

void				Character::equip(AWeapon *new_wp)
{
	wp = new_wp;
}

void				Character::attack(Enemy *enemy)
{
	if (enemy == NULL || this->wp == NULL || this->wp->getAPCost() > ap)
		return ;
	std::cout << getName() << " attacks " << enemy->getType() << " with a " << this->wp->getName() << std::endl;
	this->wp->attack();
	this->ap -= this->wp->getAPCost();
	enemy->takeDamage(this->wp->getDamage());
	if (enemy->getHP() <= 0)
		delete (enemy);
}

std::string const	Character::getName() const
{
	return name;
}

int const	Character::getAP() const
{
	return ap;
}

AWeapon		*Character::getWeapon() const
{
	return wp;
}

// Stream /////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, Character const &obj)
{
	if (obj.getWeapon())
		out << YLW << obj.getName() << " has " << obj.getAP() << " AP and carries a " << *(obj.getWeapon()) << NC << std::endl;
	else
		out << YLW << obj.getName() << " has " << obj.getAP() << " AP is unarmed" << NC << std::endl;
	return out;
}

