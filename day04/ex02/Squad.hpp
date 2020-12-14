/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 20:30:35 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/14 20:30:35 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP
# include <iostream>
# include <string>
# include "ISquad.hpp"

using std::string;
using std::cout;

// ISpaceMarine linked list
typedef struct	ism_node
{
	ISpaceMarine	*value;
	struct ism_node	*next;
}				ism_node;

class Squad : public ISquad
{

	private:
		int			count;
		ism_node	*head;

	public:
		// Colpien's form
		Squad ();
		Squad (const Squad &source);
		Squad &operator=(const Squad &source);
		virtual ~Squad ();

		int getCount() const;
		ISpaceMarine* getUnit(int) const;
		int push(ISpaceMarine*);

};

# endif
