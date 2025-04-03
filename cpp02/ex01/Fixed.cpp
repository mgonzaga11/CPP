/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:36:44 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/01 09:59:28 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->Fixed_Point = 0;
}

Fixed::Fixed(const float number){
	std::cout << "Float constructor called" << std::endl;
	this->Fixed_Point = roundf(number * 256);
}

Fixed::Fixed(const int number){
	std::cout << "Int constructor called" << std::endl;
	this->Fixed_Point = number << this->Fractional_Bits;
}

Fixed::Fixed(Fixed const &copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &copy){
	std::cout << "Copy assignment operator called" << std::endl;
	if(&copy != this){
		this->Fixed_Point = copy.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits() const {
	return this->Fixed_Point;
}

void Fixed::setRawBits( int const raw ){
	this->Fixed_Point = raw;
}

float Fixed::toFloat( void ) const{
	return((float)this->Fixed_Point / 256);
}

int Fixed::toInt( void ) const{
	return(this->Fixed_Point >> Fractional_Bits);
}

std::ostream & operator<<(std::ostream &os, const Fixed &obj ){
	os << obj.toFloat();
	return os;
}


