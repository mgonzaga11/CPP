/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:35:39 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 16:19:39 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"


AAnimal::AAnimal(void) : type("AAnimal") {
    std::cout << "AAnimal default constuctor called" << std::endl;
}


AAnimal::AAnimal(const AAnimal &other) {
	std::cout <<  "AAnimal copy constructor called" << std::endl;
    *this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
    return this->type;
}

void AAnimal::setType(std::string newType) {
    this->type = newType;
}

