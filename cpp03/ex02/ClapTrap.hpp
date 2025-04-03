/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:57:40 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/02 15:38:27 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{
	protected:
		std::string name;
		int	hitPoint;
		int	energyPoint;
		int	attackDamage;
	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap &copy);
		ClapTrap(std::string name);
		~ClapTrap(void);
		ClapTrap &operator=(const ClapTrap &copy);

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		void		setHitPoints(int new_HitPoint);
		void		setEnergyPoint(int new_EnergyPoint);
		void		setAttackDamage(int new_AttackDamage);
		void		setName(std::string newName);
		int			getHitPoints(void) const;
		int			getEnergyPoint(void) const;
		int			getAttackDamage(void) const;
		std::string	getName(void) const;
};

#endif

