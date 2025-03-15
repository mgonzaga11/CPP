/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:39:05 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/15 20:10:43 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed(Fixed &copy){
	std::cout << "Copy constructor called" << std::endl;
	if(&copy != this) {
		this->number = copy.getRawBits();
	}
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(number);
}

void Fixed::setRawBits( int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->number = raw;
}
Fixed::~Fixed(void){std::cout << "Destructor called" << std::endl;}

Fixed& Fixed::operator=(Fixed& copy){
	std::cout << "Copy assignation operator called" << std::endl;
	if(&copy != this) {
		this->number = copy.getRawBits();
	}
	return(*this);
}

