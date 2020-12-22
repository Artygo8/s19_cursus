/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 20:30:35 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/14 20:30:35 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

// Coplien's form //////////////////////////////////////////////////////////////

Squad::Squad()
{
	this->count = 0;
	this->head = NULL;
}

Squad::Squad(const Squad &source)
{
	deepCopy(source);
}

void Squad::deepCopy(const Squad &source)
{
	ism_node *tmp;

	this->count = 0;
	while (this->head)
	{
		tmp = this->head->next;
		delete (this->head->value);
		delete (this->head->value);
		this->head = tmp;
	}
	this->head = NULL;
	tmp = source.head;
	while (tmp != NULL)
	{
		this->push(tmp->value->clone());
		tmp = tmp->next;
	}
}

Squad& Squad::operator= (const Squad &source)
{
	if (this != &source)
	    deepCopy(source);
	return *this;
}

Squad::~Squad()
{
	ism_node *tmp;

	while (this->head)
	{
		tmp = this->head->next;
		delete (this->head->value);
		delete (this->head);
		this->head = tmp;
	}
}

// others //////////////////////////////////////////////////////////////////////

int		Squad::getCount() const
{
	return (count);
}

ISpaceMarine*	Squad::getUnit(int i) const
{
	ism_node *tmp;

	tmp = head;
	if (i > this->count)
		return (NULL);
	else
	{
		while (i-- > 0)
		{
			tmp = tmp->next;
		}
		return (tmp->value);
	}
	
}

int		Squad::push(ISpaceMarine* ism)
{
	ism_node *tmp_head;

	if (!ism)
		return count;
	if(head == NULL)
	{
		ism_node *new_node = new ism_node;
		new_node->value = ism;
		new_node->next = NULL;
		head = new_node;
	}
	else
	{
		tmp_head = head;
		while (tmp_head->next)
		{
			if (tmp_head->value == ism)
				return count;
			tmp_head = tmp_head->next;
		}
		if (tmp_head->value == ism)
			return count;
		ism_node *new_node = new ism_node;
		new_node->value = ism;
		new_node->next = NULL;
		tmp_head->next = new_node;
	}
	count += 1;
	return count;
}
