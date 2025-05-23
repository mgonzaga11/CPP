/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:24:46 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/22 14:42:50 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
int main()
{
	try {
		Bureaucrat a("Marcela", 152);
	}
	catch (const std::exception& e) {
		std::cerr << "Erro: " << e.what() << std::endl;
		return 1;
	}
}
