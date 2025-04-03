/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:57:32 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/02 18:38:58 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoint(10), energyPoint(10), attackDamage(0) {
    std::cout << name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoint(10), energyPoint(10), attackDamage(0) {
    std::cout << name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
    *this = copy;
    std::cout << name << " has been copied!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
    if (this != &copy) {
        name = copy.name;
        hitPoint = copy.hitPoint;
        energyPoint = copy.energyPoint;
        attackDamage = copy.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (hitPoint <= 0 || energyPoint <= 0) {
        std::cout << name << " has no energy or hit points to attack!" << std::endl;
        return;
    }
    energyPoint--;
    std::cout << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    hitPoint -= amount;
    if (hitPoint < 0) hitPoint = 0;
    std::cout << name << " takes " << amount << " damage and now has " << hitPoint << " hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoint <= 0 || energyPoint <= 0) {
        std::cout << name << " has no energy or hit points to repair!" << std::endl;
        return;
    }
    energyPoint--;
    hitPoint += amount;
    std::cout << name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
}

void ClapTrap::setHitPoints(int new_HitPoint) {
    hitPoint = new_HitPoint;
}

void ClapTrap::setEnergyPoint(int new_EnergyPoint) {
    energyPoint = new_EnergyPoint;
}

void ClapTrap::setAttackDamage(int new_AttackDamage) {
    attackDamage = new_AttackDamage;
}

void ClapTrap::setName(std::string newName) {
    name = newName;
}

int ClapTrap::getHitPoints(void) const {
    return hitPoint;
}

int ClapTrap::getEnergyPoint(void) const {
    return energyPoint;
}

int ClapTrap::getAttackDamage(void) const {
    return attackDamage;
}

std::string ClapTrap::getName(void) const {
    return name;
}
