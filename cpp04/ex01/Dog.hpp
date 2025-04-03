/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:36:51 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 15:47:44 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"

class Dog: public Animal
{
    private:

    Brain *brain;
    
    public:

    Dog(void);
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    virtual ~Dog(void);

    void makeSound() const;
    void printIdeas() const;
};

#endif