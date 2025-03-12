/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:35:14 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/11 21:46:12 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA {

	private:
		std::string	_name;
		Weapon	&_weapon;

	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack(void);
};

#endif
