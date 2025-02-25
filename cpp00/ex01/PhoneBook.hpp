/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:57:31 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/12/12 20:03:58 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <sstream>

class PhoneBook {
private:
	contact contacts[8];
	int		index;
	int 	contactnum;
	
public:
    PhoneBook();
	void	addconcts();
	void	searchcontacts();
	std::string get_input(std::string info);
};



#endif