/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:36:03 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/04/03 17:06:17 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream> 

int main()
{
	std::cout << "\nSUBJECT TEST \n" << std::endl;


	const Animal* meta = new Animal();
	const Animal* j = new Dog(); 
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
		
	std::cout << "\n MY OWN TEST \n" << std::endl;

	Dog	dog;
	Cat	cat;

	std::cout << "\nyou can see that cat and dog have the right type and the righ song\n" << std::endl;
	std::cout <<  dog.getType() << " " << std::endl;
	std::cout << cat.getType() << std::endl;
	dog.makeSound();
	cat.makeSound();


	std::cout << "\nset objects by pointer\n" << std::endl;

	const WrongAnimal* wAnimal = new WrongCat();
	const WrongCat wCat;
	
	std::cout << "\nyou can see that both have the right type\n" << std::endl;
	std::cout <<  wCat.getType() << std::endl;
	std::cout << wAnimal->getType() << std::endl;

	std::cout << "\nnow you can see that only WrongCat have the wrong sound\n" << std::endl;

	wCat.makeSound();
	wAnimal->makeSound();
	std::cout << "\nDelete all\n" << std::endl;



	delete meta;
	delete i;
	delete j;
	delete wAnimal;
}