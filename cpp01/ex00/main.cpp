/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:21:19 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/02/13 15:51:20 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    randomChump("Olivia");
    Zombie* alicia =  newZombie("Alicia");
    alicia->announce();
    delete alicia;   
    randomChump("Carlos");
    Zombie* John =  newZombie("John");
    John->announce();
    delete John;   
    return 0;
}

