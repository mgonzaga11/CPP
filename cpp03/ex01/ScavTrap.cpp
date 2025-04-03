/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:21:30 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/02 15:32:29 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include "ClapTrap.hpp" 

ScavTrap::ScavTrap() : ClapTrap("Default") {
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
    *this = copy;
    std::cout << "ScavTrap " << name << " has been copied!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
    if (this != &copy) {
        ClapTrap::operator=(copy);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " has been destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (hitPoint <= 0 || energyPoint <= 0) {
        std::cout << "ScavTrap " << name << " has no energy or hit points to attack!" << std::endl;
        return;
    }
    energyPoint--;
    std::cout << "ScavTrap " << name << " viciously attacks " << target << ", dealing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode!" << std::endl;
}
