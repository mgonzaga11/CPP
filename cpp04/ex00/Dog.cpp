/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:37:10 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 14:07:01 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	std::cout << "Dog defaut constructor called" << std::endl;
	type = "Dog";
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy) {
	*this = copy;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other) {
		setType(other.getType());
	}
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Au Au...." << std::endl;
}