/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:47:08 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/31 18:42:36 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Fixed_HPP
# define Fixed_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int Fixed_Point;
		static const int Fractional_Bits = 8;
	public:
		static const int epsilon = 1;
		Fixed();
		Fixed(Fixed const &copy);
		Fixed(const int number);
		Fixed(const float number);
		~Fixed();
		Fixed& operator=(Fixed const &other);
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		Fixed operator-(const Fixed& obj) const;
		Fixed operator+(const Fixed& obj) const;
		Fixed operator*(const Fixed& obj) const;
		Fixed operator/(const Fixed& obj) const;
		Fixed &operator++(); 
		Fixed operator++(int);
		Fixed &operator--(); 
		Fixed operator--(int);
		
		int getRawBits() const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};
std::ostream & operator<<(std::ostream &os, const Fixed &obj);




#endif