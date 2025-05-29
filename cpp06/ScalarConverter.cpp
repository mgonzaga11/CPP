/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:01:32 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/29 18:41:30 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int checkChar(std::string str);
int checkPseudo(std::string str);
int checkInt(std::string str);
int checkFloat(std::string str);
int checkDouble(std::string str);

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

int checkChar(std::string str){
	
	if (str.size() == 1 && !isdigit(str[0]))
		return(CHAR);
	return(0);
}

int checkPseudo(std::string str)
{
	std::string pseudos[6] = {"nan", "+inf", "-inf", "nanf", "+inff", "-inff"};
	for (int i = 0; i < 6; i++)
	{
		if (str == pseudos[i])
			return(PSEUDO);
	}
	return(0);
}

int checkNumbers(std::string str)
{
	if (((str[0] == '+' || str[0] == '-' || isdigit(str[0])) && isdigit(str[1])) 
	|| (str.size() == 1 &&  isdigit(str[0]))){
}

}
int checkFloat(std::string str);
int checkDouble(std::string str);


std::string	defineType(std::string str){

	checkChar
	checkPseudo
	checkInt
	checkFloat
	checkDouble
		
}

