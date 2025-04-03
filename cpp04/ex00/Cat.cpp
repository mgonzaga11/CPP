/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:36:34 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 15:53:14 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	std::cout << "Cat defaut constructor called" << std::endl;
	type = "Cat";
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy) {
	*this = copy;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(Cat const &other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Miauuuuuu...." << std::endl;
}