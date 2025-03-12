/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:35:25 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/11 22:01:26 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "HumanA.hpp"
# include <string>

class	HumanB {
	private:
		std::string	_name;
		Weapon	*_weapon;

	public:
		HumanB(std::string name);

		void	attack(void);
		void	setWeapon(Weapon &weapon);

};

#endif
