/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:46:53 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/31 19:14:17 by mgonzaga         ###   ########.fr       */
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

bool Fixed::operator>(const Fixed& other) const {
	return Fixed_Point > other.Fixed_Point;
}

bool Fixed::operator<(const Fixed& other) const {
	return Fixed_Point < other.Fixed_Point;
}

bool Fixed::operator>=(const Fixed& other) const {
	return *this > other || *this == other;
}

bool Fixed::operator<=(const Fixed& other) const {
	return *this < other || *this == other;
}

bool Fixed::operator==(const Fixed& other) const {
	return Fixed_Point == other.Fixed_Point;
}

bool Fixed::operator!=(const Fixed& other) const {
	return !(*this == other);
}

Fixed Fixed::operator-(const Fixed& other) const{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator+(const Fixed& other) const{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const{
	return Fixed(this->toFloat() * other.toFloat());
}
