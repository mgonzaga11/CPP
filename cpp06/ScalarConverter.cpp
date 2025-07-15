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


bool	checkInt(std::string str){
	for (unsigned int i = 1; i < str.size(); i++)
		if (!isdigit(str[i]))
			return(0);
	return(1);
}

bool	checkFloat(std::string str){
	int	point = 0;
	unsigned int 	size = str.size();

	for (unsigned int i = 1; i < (size - 1); i++){
		if ((str[i] != '.' && !isdigit(str[i])) || point > 1)
			return(0);
		if (str[i] == '.')
			point++;
	}
	if (str[size - 1] == 'f')
		return(1);
	return(0);
}

bool	checkDouble(std::string str){
	int				point = 0;
	unsigned int	size = str.size();

	for (unsigned int i = 1; i < size ; i++){
		if ((str[i] != '.' && !isdigit(str[i])) || point > 1)
			return(0);
		if (str[i] == '.')
			point++;
	}
	return(1);
}



bool	ScalarConverter::defineType(std::string str){
	std::string pseudos[6] = {"nan", "+inf", "-inf", "nanf", "+inff", "-inff"};
	for (int i = 0; i < 6; i++){
		if (str == pseudos[i]){
			type = PSEUDO;
			return(0);
		}
	}
	if (str.size() == 1 && !isdigit(str[0])){
		type = CHAR;
		return(0);
	}
	if (((str[0] == '+' || str[0] == '-' || isdigit(str[0])) && isdigit(str[1])) 
		|| (str.size() == 1 &&  isdigit(str[0]))){
		if (checkInt(str)){
			type = INT;
			return(0);
		}
		if (checkFloat(str)){
			type = FLOAT;
			return(0);
		}
		if(checkDouble(str)){
			type = DOUBLE;
			return(0);
		}
	}
	std::cout << "Error:invalid parameters" << std::endl;
	return(1);

