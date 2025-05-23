/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:36:29 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 16:48:47 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include "WrongAnimal.hpp"
class	WrongCat : public WrongAnimal {

public:
	WrongCat(void);
	~WrongCat(void);
	WrongCat(WrongCat const &other);

	WrongCat	&operator=(WrongCat const &other);

	void	makeSound(void) const;
};

#endif