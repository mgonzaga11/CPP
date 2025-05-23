/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:33:42 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 18:43:15 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
    protected:

    std::string type;

    public:
	
	AAnimal(void);
    AAnimal(std::string type);
    virtual ~AAnimal(void);
    AAnimal(const AAnimal &other);
    AAnimal &operator=(const AAnimal &other);
    
    std::string getType() const;
    void setType(std:: string newType);

    virtual void makeSound() const = 0;
};

#endif