/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:36:03 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 18:44:46 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
    AAnimal* c = new Cat();
    AAnimal* d = new Dog();

    AAnimal* animal = new AAnimal();
    animal->makeSound();

    c->makeSound();
    d->makeSound();

    delete c;
    delete d;

    return 0;
  }