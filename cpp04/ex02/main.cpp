/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:36:03 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 14:51:03 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
//#include "WrongCat.hpp"
#include <iostream>

int main()
{
//const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
Cat m;
m.makeSound();
i->makeSound(); //will output the cat sound!
j->makeSound();
delete j;
delete i;
//meta->makeSound();
return (0);
}