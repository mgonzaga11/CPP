/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:57:45 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/02 19:00:54 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    FragTrap frag1("Protector");
    ScavTrap scav("Assassin");
    
    frag1.setAttackDamage(30);
    scav.setAttackDamage(25);

    std::cout << "\n--- Battle Begins ---\n";
    frag1.attack(scav.getName());
    scav.takeDamage(frag1.getAttackDamage());

    scav.attack(frag1.getName());
    frag1.takeDamage(scav.getAttackDamage());

    std::cout << "\n--- Repair Phase ---\n";
    frag1.beRepaired(20);
    scav.beRepaired(20);
    
    std::cout << "\n--- Different methods ---\n";
    frag1.highFivesGuys();
    scav.guardGate();

    std::cout << "\n--- Continued Battle ---\n";
    frag1.attack(scav.getName());
    scav.takeDamage(frag1.getAttackDamage());
    scav.attack(frag1.getName());
    frag1.takeDamage(scav.getAttackDamage());

    std::cout << "\n--- End of Simulation ---\n";
    return 0;
}
