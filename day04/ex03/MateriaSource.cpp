/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 00:00:23 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 00:00:23 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Coplien's form //////////////////////////////////////////////////////////////

MateriaSource::MateriaSource()
{
	learned[0] = 0;
	learned[1] = 0;
	learned[2] = 0;
	learned[3] = 0;
}

void	MateriaSource::deepCopy(const MateriaSource &source)
{
	learned[0] = source.learned[0];
	learned[1] = source.learned[1];
	learned[2] = source.learned[2];
	learned[3] = source.learned[3];
}

MateriaSource::MateriaSource(const MateriaSource &source)
{
	deepCopy(source);
}

MateriaSource& MateriaSource::operator = (const MateriaSource &source)
{
	deepCopy(source);
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete (learned[i]);
		learned[i] = NULL;
	}
}

// others //////////////////////////////////////////////////////////////////////

void MateriaSource::learnMateria(AMateria *am)
{
	for (int i = 0; i < 4; i++)
	{
		if (learned[i] == NULL)
		{
			learned[i] = am;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	srand(time(NULL));
	int r = rand() % 4;
	for (int i = 0; i < 4; i++)
	{
		if (learned[(r + i) % 4] && learned[(r + i) % 4]->getType() == type)
		{
			return learned[(r + i) % 4]->clone();
		}
	}
	return 0;
}
