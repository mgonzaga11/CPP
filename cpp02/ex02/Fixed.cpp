/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:46:53 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/01 09:54:13 by mgonzaga         ###   ########.fr       */
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

// Pre-increment 
Fixed &Fixed::operator++(void){
	this->Fixed_Point++;
	return(*this);
}

// Pre-decrement 
Fixed &Fixed::operator--(void){
	this->Fixed_Point--;
	return(*this);
}

// Post-increment 
Fixed Fixed::operator++(int){
	Fixed temp(*this);
	operator++();
	return(temp);
}

// Post-decrement
Fixed Fixed::operator--(int){
	Fixed temp(*this);
	operator--();
	return(temp);
}

int Fixed::getRawBits() const {
//	std::cout << "getRawBits member function called" << std::endl;
	return this->Fixed_Point;
}

void Fixed::setRawBits( int const raw ){
	//std::cout << "setRawBits member function called" << std::endl;
	this->Fixed_Point = raw;
}

float Fixed::toFloat( void ) const{
	return((float)this->Fixed_Point / 256);
}

int Fixed::toInt( void ) const{
	return(this->Fixed_Point >> Fractional_Bits);
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
	return(a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	return(a > b ? a : b);
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b){
	return(a < b ? a : b);
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b){
	return(a > b ? a : b);
}

std::ostream & operator<<(std::ostream &os, const Fixed &obj ){
	os << obj.toFloat();
	return os;
}