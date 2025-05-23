/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:37:24 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 16:48:37 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <string>
# include <iostream>

class	WrongAnimal {

protected:
	std::string	type;

public:
	WrongAnimal(void);
	~WrongAnimal(void);
	WrongAnimal(WrongAnimal const &other);
	
	WrongAnimal	&operator=(WrongAnimal const &other);
	
	std::string	getType(void) const;
	void	setType(std::string const &newType);
	void	makeSound(void) const;
};

#endif