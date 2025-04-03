/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:57:45 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/02 18:54:45 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("Warrior");
    ScavTrap scav("Defender");

    clap.setAttackDamage(3);
    scav.setAttackDamage(4);

    std::cout << "\n--- Battle Begins ---\n";
    clap.attack(scav.getName());
    scav.takeDamage(clap.getAttackDamage());

    scav.attack(clap.getName());
    clap.takeDamage(scav.getAttackDamage());

    std::cout << "\n--- Repair Phase ---\n";
    clap.beRepaired(5);
    scav.beRepaired(5);

    std::cout << "\n--- Continued Battle ---\n";
    clap.attack(scav.getName());
    scav.takeDamage(clap.getAttackDamage());
    scav.attack(clap.getName());
    clap.takeDamage(scav.getAttackDamage());

    std::cout << "\n--- End of Simulation ---\n";
    return 0;
}