/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:01:37 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/07/16 18:18:51 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv){
	if (argc != 2){
		std::cout << "Error: " << "invalid number of arguments" << std::endl;
			return(-1);
	}
	ScalarConverter::convert(argv[1]);
	return(0);
}