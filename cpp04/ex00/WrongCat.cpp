/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:36:38 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 16:47:08 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
	setType("WrongCat");
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &param) : WrongAnimal(param) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = param;
}

WrongCat	&WrongCat::operator=(WrongCat const &param) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &param) {
		setType(param.getType());
	}
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "Wrong cat sound" << std::endl;
}