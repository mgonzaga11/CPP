/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:43:31 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/12/11 18:54:42 by mgonzaga         ###   ########.fr       */
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
	if(contactnum < 8)
		contactnum++;	
}

std::string PhoneBook::get_input(std::string info)
{
	std::string line;
	std::cout << info << std::endl;
	getline(std::cin, line);
	return(line);
}

std::string	Columnformat(std::string	text, unsigned int size)
{
	if(text.length() > size)
		return text.substr(0, size - 1) + ".";
	return(text);	
}
int 	Getindex()
{
	while(1)
	{
		
	}
}


void	PhoneBook::searchcontacts()
{
	std::cout << std::setw(10) << Columnformat("index", 10) << "|";
	std::cout << std::setw(10) << Columnformat("Name", 10) << "|";
	std::cout << std::setw(10) << Columnformat("Last Name", 10) << "|";
	std::cout << std::setw(10) << Columnformat("Nickname", 10) << "|";
	for(int i = 0; i < contactnum; i++)
	{
		std::cout << std::setw(10) << (i + 1) << "|";
		std::cout << std::setw(10) << Columnformat(contacts[i].GetFirstName(), 10) << "|";
		std::cout << std::setw(10) << Columnformat(contacts[i].GetLastName(), 10) << "|";
		std::cout << std::setw(10) << Columnformat(contacts[i].GetNickName(), 10) << "|" << std::endl;
	}
	int i = GetIndex();

	
}

PhoneBook::PhoneBook() {
}