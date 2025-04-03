/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:35:39 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 15:50:42 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"


Animal::Animal(void) : type("Animal") {
    std::cout << "Animal default constuctor called" << std::endl;
}


Animal::Animal(const Animal &other) {
	std::cout <<  "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}

void Animal::setType(std::string newType) {
    this->type = newType;
}


void Animal::makeSound() const {
    std::cout << "Generic animal sound." << std::endl;
}