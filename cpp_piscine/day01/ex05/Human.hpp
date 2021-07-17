/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 18:23:49 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 19:55:06 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMAN_HPP
# define HUMAN_HPP
# include "Brain.hpp"

typedef std::string string;

class Human {

public:

	Human();
	~Human();
	Brain	&getBrain();
	std::string identify();

private:

	Brain	brain;

};

#endif
