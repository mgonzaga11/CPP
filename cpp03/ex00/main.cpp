/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:57:45 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/02 15:47:10 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap clap1("Warrior");
    ClapTrap clap2("Defender");

    clap1.setAttackDamage(3);
    clap2.setAttackDamage(4);

    std::cout << "\n--- Battle Begins ---\n";
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());

    clap2.attack(clap1.getName());
    clap1.takeDamage(clap2.getAttackDamage());

    std::cout << "\n--- Repair Phase ---\n";
    clap1.beRepaired(5);
    clap2.beRepaired(5);

    std::cout << "\n--- Continued Battle ---\n";
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
    clap2.attack(clap1.getName());
    clap1.takeDamage(clap2.getAttackDamage());

    std::cout << "\n--- End of Simulation ---\n";
    return 0;
}