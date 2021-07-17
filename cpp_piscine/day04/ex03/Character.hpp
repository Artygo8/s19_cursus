/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 00:00:23 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 00:00:23 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

using std::string;
using std::cout;


class Character : public ICharacter
{

	private:
		std::string		name;
		AMateria*		inv[4];

	public:
		// Colpien's form
		Character (std::string name = "default hero");
		Character (const Character &source);
		Character &operator=(const Character &source);
		virtual ~Character ();

		void	deepCopy(const Character &source);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

};

std::ostream &operator<<(std::ostream &out, Character const &obj);

# endif
