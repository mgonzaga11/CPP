/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:36:34 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 17:17:34 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::~Cat(void) {
    std::cout << "Cat destructor called" << std::endl;
    delete brain; 
}

Cat::Cat(Cat const &copy) : Animal(copy) {
    type = copy.type;
    brain = new Brain(*copy.brain); 
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

void Cat::makeSound(void) const {
    std::cout << "Miauuu...." << std::endl;
}

Brain	*Cat::getBrain(void) const{
	return(this->brain);
}