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
	contacts[index].SetFirstName(get_input("Enter the name:"));
	contacts[index].SetLastName(get_input("Enter the lastname:"));
	contacts[index].SetNickName(get_input("Enter the nickname"));
	contacts[index].SetPhoneNumber(get_input("Enter the phonenumber"));
	contacts[index].SetDarkestSecret(get_input("Enter the darkestsecret"));
	
	index = (index + 1) % 8;	
}

std::string PhoneBook::get_input(std::string info)
{
	std::string line;
	std::cout << info << std::endl;
	getline(std::cin, line);
	return(line);
}

void	PhoneBook::searchcontacts()
{
	
}

PhoneBook::PhoneBook() {
}