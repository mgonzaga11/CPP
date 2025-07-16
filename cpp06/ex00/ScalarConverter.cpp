/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:01:32 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/07/16 18:27:13 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	checkInt(std::string str);
bool	checkFloat(std::string str);
bool	checkDouble(std::string str);
void	printPseudo(std::string str);
void	convertInt(std::string str, int type);
void	convertFloat(std::string str, int type);
void	convertDouble(std::string str, int type);
void	convertChar(std::string str, int type);

ScalarConverter::ScalarConverter(void) {}

// copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

// copy assignment operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

// destructor
ScalarConverter::~ScalarConverter(void) {}

void	ScalarConverter::convert(const std::string &str){
	int type = defineType(str);

	if (type < 0)
		return ;
	switch (type)
	{
	case 0:
		printPseudo(str);
		break;
	case 1:
		convertChar(str, type);
		break;
	case 2:
		convertInt(str, type);
		break;
	case 3:
		convertFloat(str, type);
		break;
	case 4:
		convertDouble(str, type);
		break;
	default:
		break;
	}
}

int	ScalarConverter::defineType(const std::string &str){
	std::string pseudos[6] = {"nan", "+inf", "-inf", "nanf", "+inff", "-inff"};
	for (int i = 0; i < 6; i++){
		if (str == pseudos[i]){
			return(PSEUDO);
		}
	}
	if (str.size() == 1 && !isdigit(str[0])){
		return(CHAR);
	}
	if (((str[0] == '+' || str[0] == '-' || isdigit(str[0])) && isdigit(str[1])) 
		|| (str.size() == 1 &&  isdigit(str[0]))){
		if (checkInt(str)){
			return(INT);
		}
		if (checkFloat(str)){
			return(FLOAT);
		}
		if(checkDouble(str)){
			return(DOUBLE);
		}
	}
	std::cout  << "Error: " << "invalid parameters" << std::endl;
	return(-1);
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

void printPseudo(std::string str)
{
	std::cout << "char: " << "impossible" << std::endl;//é impossível representar esses valores em char e int, 
	std::cout << "int: " << "impossible" << std::endl;	//já que eles são específicos de números de ponto flutuante
	if (str == "nanf" || str == "nan")
	{
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
	else if (str == "+inff" || str == "+inf")
	{
		std::cout << "float: " << "+inff" << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
	}
	else if (str == "-inff" || str == "-inf")
	{
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	}
}

void	printChar(std::string str, char c){
	if (atol(str.c_str()) < CHAR_MIN || atol(str.c_str()) > CHAR_MAX)
		std::cout <<  "char: " << "impossible" << std::endl;
	else if (!isprint(c))
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << c << "'" << std::endl;
}

void	printInt(std::string str, int i){
	if (atol(str.c_str()) < INT_MIN || atol(str.c_str()) > INT_MAX)
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void	printFloat(std::string str, float f, int type){
	if ((atol(str.c_str()) < INT_MIN || atol(str.c_str()) > INT_MAX) 
		&& (type == INT))
		std::cout <<  "float: " << "impossible" << std::endl;
	else
		std::cout << "float: "<< std::fixed << std::setprecision(1) << f << "f"  << std::endl;
}

void	printDouble(std::string str, double d, int type){
	if ((atol(str.c_str()) < INT_MIN || atol(str.c_str()) > INT_MAX) 
		&& (type == INT))
		std::cout << "double: " << "impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}


void	convertChar(std::string str, int type){
	char c = str[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	printChar(str, c);
	printInt(str, i);
	printFloat(str, f, type);
	printDouble(str, d, type);
}

void	convertInt(std::string str, int type){
	int i = atoi(str.c_str());
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	printChar(str, c);
	printInt(str, i);
	printFloat(str, f, type);
	printDouble(str, d, type);
}

void	convertFloat(std::string str, int type){
	float f = strtof(str.c_str(), NULL);
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	printChar(str, c);
	printInt(str, i);
	printFloat(str, f, type);
	printDouble(str, d, type);
}

void	convertDouble(std::string str, int type){
	double d = strtod(str.c_str(), NULL);
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	printChar(str, c);
	printInt(str, i);
	printFloat(str, f, type);
	printDouble(str, d, type);
}