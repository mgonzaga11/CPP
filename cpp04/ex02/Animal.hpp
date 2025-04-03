/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:33:42 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 13:35:19 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>


class Animal
{
    protected:

    std::string type;

    public:
	
	Animal(void);
    Animal(std::string type);
    virtual ~Animal(void);
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    
    std::string getType() const;
    void setType(std:: string newType);

    virtual void makeSound() const;
};

#endif