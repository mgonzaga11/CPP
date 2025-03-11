/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:22:32 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/09 18:23:01 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <string>
#include <iostream>

int	main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*strPTR = &str;
	std::string	&strREF = str;

	std::cout << "The memory address: " << &str << std::endl;
	std::cout << "The memory address: " << strPTR << std::endl;
	std::cout << "The memory address: " << &strREF << std::endl;

	std::cout << "The value pointed: " << str << std::endl;
	std::cout << "The value pointed: " << *strPTR << std::endl;
	std::cout << "The value pointed: " << strREF << std::endl;

	return (0);
}
