/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:36:03 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 18:52:25 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	std::cout << "\n SUBJECT TEST \n" << std::endl;


	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << "\n\n MY OWN TEST \n\n" << std::endl;


    std::cout << "Creating animals...\n" << std::endl;

    const int SIZE = 4;  
    Animal* animals[SIZE];

  
    for (int i = 0; i < SIZE / 2; i++)
        animals[i] = new Dog();
    for (int i = SIZE / 2; i < SIZE; i++)
        animals[i] = new Cat();

    std::cout << "\nTesting sounds...\n" << std::endl;
    for (int i = 0; i < SIZE; i++)
        animals[i]->makeSound();

    std::cout << "\nTesting deep copy...\n" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdeas("I want a bone!", 0);
    
    Dog copyDog = originalDog; 
    std::cout << "Original idea: " << originalDog.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Copied idea: " << copyDog.getBrain()->getIdeas(0) << std::endl;

    originalDog.getBrain()->setIdeas("I changed my mind!", 0);
    std::cout << "After modifying original..." << std::endl;
    std::cout << "Original idea: " << originalDog.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Copied idea: " << copyDog.getBrain()->getIdeas(0) << std::endl;

    std::cout << "\nDeleting animals...\n" << std::endl;
    for (int i = 0; i < SIZE; i++)
        delete animals[i];  

    std::cout << "\nTest finished. Check for memory leaks!\n" << std::endl;
    return 0;
}
