/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:35:18 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/11 21:46:34 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name) {}

void	HumanB::attack(void) {
	if (_weapon)
		std::cout << _name << " attack with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}
