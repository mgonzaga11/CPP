/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:28:01 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/07 15:11:46 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie(void) {};

Zombie::~Zombie(void) {
	std::cout << "Zombie " << _nameZombie << " has been destroyed." << std::endl;
}

void	Zombie::announce(void) {
	std::cout << _nameZombie << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setNameZombie(std::string &nameZombie) {
	_nameZombie = nameZombie;
}