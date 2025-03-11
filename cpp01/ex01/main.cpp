/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:52:48 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/07 15:16:22 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	*horde = zombieHorde(5, "John");

	for (int i = 0; i < 5; i++) {
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}