/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:43:31 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/12/12 19:50:03 by mgonzaga         ###   ########.fr       */
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
	{
		contactnum++;		
	}
}

std::string PhoneBook::get_input(std::string info)
{
	std::string line;
	std::cout << info << std::endl;
	while(1)
	{
		getline(std::cin, line);
		if (std::cin.eof()) 
		{
			std::cout << "\nEOF detected. Exiting program." << std::endl;
			exit(0);
		}
		else if (line.empty()) {
				std::cout << "Input cannot be empty. Type again." << std::endl;}
		else {
			break;
		}
	}		
	return(line);
}

std::string	Columnformat(std::string	text, unsigned int size)
{
	if(text.length() > size)
		return text.substr(0, size - 1) + ".";
	return(text);	
}
int 	GetIndex()
{
	std::string input;
	int index;
	while(1)
	{
		std::cout << std::endl;
		std::cout << "Enter contact number (1-8)" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof()) 
		{
			std::cout << "\nEOF detected. Exiting program." << std::endl;
			exit(0);
		}
		std::stringstream ss(input);
   		ss >> index;
		if (ss.fail())
		{
			continue;
		}
		if(index > 0 && index <= 8)
			return index - 1;
		std::cout << "Invalid index" << std::endl;
		}
		
}



void	PhoneBook::searchcontacts()
{
	std::cout << std::setw(10) << Columnformat("index", 10) << "|";
	std::cout << std::setw(10) << Columnformat("Name", 10) << "|";
	std::cout << std::setw(10) << Columnformat("Last Name", 10) << "|";
	std::cout << std::setw(10) << Columnformat("Nickname", 10) << "|";
	std::cout << std::endl;
	for(int i = 0; i < contactnum; i++)
	{
		std::cout << std::setw(10) << (i + 1) << "|";
		std::cout << std::setw(10) << Columnformat(contacts[i].GetFirstName(), 10) << "|";
		std::cout << std::setw(10) << Columnformat(contacts[i].GetLastName(), 10) << "|";
		std::cout << std::setw(10) << Columnformat(contacts[i].GetNickName(), 10) << "|" ;
		std::cout << std::endl;
	}
	int i = GetIndex();
	if (contacts[i].GetFirstName().empty())
	{
        std::cout << "The conctact is empty." << std::endl;
	}
	else
	{
		std::cout << "Name: " << contacts[i].GetFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[i].GetLastName() << std::endl;
		std::cout << "Nick Name " << contacts[i].GetNickName() << std::endl;
		std::cout << "Phone Number " << contacts[i].GetPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[i].GetDarkestSecret() << std::endl;
	}
}

PhoneBook::PhoneBook() {
	index = 0;
	contactnum = 0;
}