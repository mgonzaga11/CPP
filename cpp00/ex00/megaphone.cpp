/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:12:19 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/11/09 20:24:32 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int argc, char **argv)
{

	if(argc > 1)
	{
		for(int j = 1; j < argc; j++)
		{
			for(int i = 0; argv[j][i] != '\0'; i++)
			{
				char c = std::toupper(argv[j][i]);	
				std::cout << c;
			}
			if(j < argc - 1)
				std::cout << " ";
		}
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return(1);
	}
	std::cout << std::endl;	
	return(0);	
}