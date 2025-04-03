/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:36:54 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/01 09:36:31 by mgonzaga         ###   ########.fr       */
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
		Fixed(); 
		Fixed(Fixed const &object);
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed& operator=(Fixed const &object);
		~Fixed();
		int getRawBits() const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};
std::ostream & operator<<(std::ostream &os, const Fixed &obj);

#endif