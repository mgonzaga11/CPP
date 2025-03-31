/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:38:56 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/30 16:02:31 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int number;
		static const int fixed_number = 8;
	public:
		Fixed(void);
		Fixed(Fixed& copy);
		~Fixed(void);
		
		Fixed& operator=(Fixed& copy);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};



#endif