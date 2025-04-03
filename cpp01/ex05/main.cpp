/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:15:13 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/17 14:20:10 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av) {
	Harl	harl;
	
	if (ac != 2) {
		std::cout << "Wrong number of arguments, try: [./harl], [level]" << std::endl;
		return (1);
	}
	harl.complain(av[1]);
	return (0);
}