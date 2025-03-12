/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:35:38 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/11 21:48:01 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string typeWeapon) {
	setType(typeWeapon);
}

void	Weapon::setType(std::string type) {
	_type = type;
}

std::string	Weapon::getType(void) const{
	return (_type);
}
