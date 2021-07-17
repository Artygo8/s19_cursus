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

#define TITLE_BLU(str) std::cout << R_BLU << str << NC << std::endl;
#define TITLE_MGN(str) std::cout << R_MGN << str << NC << std::endl;
#define TITLE_CYN(str) std::cout << R_CYN << str << NC << std::endl;

int main()
{

	{
		TITLE_BLU("Testing methods on a Character with one AMateria:");
		AMateria *c = new Cure();
		ICharacter* moi = new Character("moi");

		std::cout << *c;

		TITLE_BLU("equip c_clone");
		moi->equip(c->clone());
		TITLE_BLU("equip c_clone");
		moi->equip(c->clone());
		TITLE_BLU("equip c_clone");
		moi->equip(c->clone());
		TITLE_BLU("unequip 0");
		moi->unequip(0);
		TITLE_BLU("use 0:");
		moi->use(0, *moi);
		TITLE_BLU("use 1:");
		moi->use(1, *moi);
		TITLE_BLU("use 2:");
		moi->use(2, *moi);
		TITLE_BLU("use 3:");
		moi->use(3, *moi);

		std::cout << *c;

		delete(c);
		delete(moi);
	}

	{
		TITLE_MGN("Testing deep_copy of a character:");

		Character* moi = new Character("moi");
		AMateria *i = new Ice();
		AMateria *c = new Cure();

		TITLE_MGN("equip i");
		moi->equip(i);
		TITLE_MGN("equip c");
		moi->equip(c);

		TITLE_MGN("make deep_copy");
		Character* toi = new Character(*moi);

		TITLE_MGN("delete original");
		delete(moi);

		TITLE_MGN("use 0:");
		toi->use(0, *toi);
		TITLE_MGN("use 1:");
		toi->use(1, *toi);
		TITLE_MGN("use 2:");
		toi->use(2, *toi);
		TITLE_MGN("use 3:");
		toi->use(3, *toi);

		delete(toi);
	}

	{
		TITLE_CYN("Original Main:");

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