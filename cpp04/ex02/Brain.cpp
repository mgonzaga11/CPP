/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:33:17 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 15:43:00 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void){
	std::cout << "Brain Default constructor called" << std::endl;
	for (unsigned int i = 0; i < 100; i++)
		ideas[i] = "Empty";
}

Brain::Brain(Brain const &other){
	std::cout <<  "Brain copy constructor called" << std::endl;
	*this = that;
}

Brain::~Brain(void){
	std::cout << "Brain destructor called" << std::endl;
}

Brain  &Brain::operator=(Brain const &other){
	std::cout << "Brain copy assignment operator called" << std::endl;
	if(this != &that)
		for (int i = 0; i < 100; i++)
			ideas[i] = that.ideas[i];
	return(*this);
}

 std::string Brain::getIdeas(int index){
	if (index < 100)
		return(ideas[index]);
	else
		std::cout << "index out of range" << std::endl;
	return(NULL);
}

void	Brain::setIdeas(std::string idea, int index){
	if (index < 100)
		ideas[index] = idea;
	else
		std::cout << "index out of range" << std::endl;
}