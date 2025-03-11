/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:38:30 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/02/13 15:28:46 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP


#include <iostream>

class Zombie{

	private:
		std::string Name;
	public:
		Zombie(std::string zombieName);
		~Zombie();
		void announce();
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);


#endif
