/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 00:00:23 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 00:00:23 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

using std::string;
using std::cout;


class MateriaSource : public IMateriaSource
{

	private:
		AMateria	*learned[4];

	public:
		// Colpien's form
		MateriaSource ();
		MateriaSource (const MateriaSource &source);
		MateriaSource &operator=(const MateriaSource &source);
		virtual ~MateriaSource ();

		void	deepCopy(const MateriaSource &source);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);

};

# endif
