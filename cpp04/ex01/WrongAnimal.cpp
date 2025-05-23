/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:37:11 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 16:48:34 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &other) {
	std::cout << "WrongAnimal copy assignment called" << std::endl;
	if (this != &other) {
		type = other.type;
	}
	return (*this);
}

std::string	WrongAnimal::getType(void) const {
	return (type);
}

void	WrongAnimal::setType(std::string const &newType) {
	type = newType;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "Wrong animal sound" << std::endl;
}