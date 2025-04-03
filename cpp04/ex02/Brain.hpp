/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:33:07 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 15:42:16 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain{
	private:
		std::string ideas[100];
	public:
		Brain(void);
		Brain(Brain const &other);
		~Brain(void);
		Brain &operator=(Brain const &other);

		void		setIdeas(std::string ideas, int index);
		std::string getIdeas(int index);

};

#endif