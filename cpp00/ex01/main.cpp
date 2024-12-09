/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:52:04 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/12/03 19:59:53 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook PhoneBook;
	std::string input;

	while(1)
	{
		std::cout <<"					PHONEBOOK           "<< std::endl;
		std::cout << "Type ADD to add contact to phone book" << std::endl;
		std::cout << "Type SEARCH to search for a contact in the phonebook" << std::endl;
		std::cout << "Type EXIT to end the schedule" << std::endl;
		std::cout << "Choose one option: ";

		getline(std::cin, input);
		if(input == "ADD")
			PhoneBook.addconcts();
		else if(input == "SEARCH")
			
			
	}
	
}