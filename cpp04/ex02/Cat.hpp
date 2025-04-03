/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:36:23 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 15:47:25 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"

class Cat: public Animal
{
    private:

    Brain *brain;
    
    public:

    Cat(void);
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    virtual ~Cat(void);

    void makeSound() const;
    void printIdeas() const;
};

#endif