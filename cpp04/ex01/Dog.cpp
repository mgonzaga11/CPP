/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:37:10 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 18:52:08 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
    brain = new Brain(); 
}

Dog::~Dog(void) {
    std::cout << "Dog destructor called" << std::endl;
    delete brain;  
}

Dog::Dog(Dog const &copy) : Animal(copy) {
    type = copy.type;
    brain = new Brain(*copy.brain);  
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;

        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "Au Au...." << std::endl;
}

Brain	*Dog::getBrain(void) const{
	return(this->brain);
}