/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:43:31 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/12/05 17:28:12 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::addconcts()
{
	contact[contact->get_index()].SetFirstName(get_input("Enter the name:"));
	contact[contact->get_index()].SetLastName(get_input("Enter the lastname:"));
	contact[contact->get_index()].SetNickName(get_input("Enter the nickname"));
	contact[contact->get_index()].SetPhoneNumber(get_input("Enter the phonenumber"));
	contact[contact->get_index()].SetDarkestSecret(get_input("Enter the darkestsecret"));
	
	contact->index_number();	
}

std::string PhoneBook::get_input(std::string info)
{
	std::string line;
	std::cout << info << std::endl;
	getline(std::cin, line);
	return(line);
}

PhoneBook::PhoneBook() {
}