/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 00:00:23 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 00:00:23 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

int main(int argc, char const *argv[])
{

	{
		std::cout << R_RED << "Testing methods on a Character with one AMateria:" << NC << std::endl;
		AMateria *c = new Cure();
		ICharacter* moi = new Character("moi");

		std::cout << *c;

		std::cout << R_YLW << "equip c_clone" << NC << std::endl;
		moi->equip(c->clone());
		std::cout << R_YLW << "equip c_clone" << NC << std::endl;
		moi->equip(c->clone());
		std::cout << R_YLW << "equip c_clone" << NC << std::endl;
		moi->equip(c->clone());
		std::cout << R_YLW << "unequip 0" << NC << std::endl;
		moi->unequip(0);
		std::cout << R_YLW << "use 0:" << NC << std::endl;
		moi->use(0, *moi);
		std::cout << R_YLW << "use 1:" << NC << std::endl;
		moi->use(1, *moi);
		std::cout << R_YLW << "use 2:" << NC << std::endl;
		moi->use(2, *moi);
		std::cout << R_YLW << "use 3:" << NC << std::endl;
		moi->use(3, *moi);

		std::cout << *c;

		delete(c);
		delete(moi);
	}

	{
		std::cout << R_RED << "Testing deep_copy of a character:" << NC << std::endl;

		Character* moi = new Character("moi");
		AMateria *i = new Ice();
		AMateria *c = new Cure();

		std::cout << R_YLW << "equip i" << NC << std::endl;
		moi->equip(i);
		std::cout << R_YLW << "equip c" << NC << std::endl;
		moi->equip(c);

		std::cout << R_YLW << "make deep_copy" << NC << std::endl;
		Character* toi = new Character(*moi);

		std::cout << R_YLW << "delete original" << NC << std::endl;
		delete(moi);

		std::cout << R_YLW << "use 0:" << NC << std::endl;
		toi->use(0, *toi);
		std::cout << R_YLW << "use 1:" << NC << std::endl;
		toi->use(1, *toi);
		std::cout << R_YLW << "use 2:" << NC << std::endl;
		toi->use(2, *toi);
		std::cout << R_YLW << "use 3:" << NC << std::endl;
		toi->use(3, *toi);

		delete(toi);
	}

	{
		std::cout << R_RED << "Original Main:" << NC << std::endl;

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* moi = new Character("moi");
		AMateria* tmp;

		tmp = src->createMateria("ice");
		moi->equip(tmp);
		tmp = src->createMateria("cure");
		moi->equip(tmp);

		ICharacter* bob = new Character("bob");
		moi->use(0, *bob);
		moi->use(1, *bob);

		delete bob;
		delete moi;
		delete src;
	}

	return 0;
}