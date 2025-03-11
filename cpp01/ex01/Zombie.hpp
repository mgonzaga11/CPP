/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:06:49 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/07 15:11:49 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class	Zombie {
	private:
		std::string	_nameZombie;

	public:
		Zombie(void);
		~Zombie(void);

		void	announce(void);
		void	setNameZombie(std::string &nameZombie);
};

Zombie	*zombieHorde(int N, std::string name);

#endif
