/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:51:34 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/07/16 19:58:37 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(void){};

Base *generate(void){
	switch (rand() % 3)
	{
	case 0:
		return(new A);
	case 1:
		return(new B);
	case 2:
		return(new C);
	default:
		return(NULL);
	}
}

//dynamic_cast: É usado para converter ponteiros
//ou referências de uma classe base para uma classe
//derivada, mas ele verifica se a conversão é segura
//em tempo de execução. Se não for, retorna um ponteiro
//nulo ou lança uma exceção.

void	identify(Base *p){
	if(dynamic_cast<A*>(p))
		std::cout << "It's an A class"  << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "It's an B class"  << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "It's an C class"  << std::endl;
	else
		std::cout << "It's a invalid class"  << std::endl;
}

void	identify(Base &p){
	try
	{
		A &a = dynamic_cast<A&>(p); //em caso de falha, ele lança uma exceção do tipo std::bad_cast.
		std::cout << "It's an A class"  << std::endl;
		(void)a;
		return ;
	}
	catch (std::exception &e) {}
	try
	{
		B &b = dynamic_cast<B&>(p); //em caso de falha, ele lança uma exceção do tipo std::bad_cast.
		std::cout << "It's an B class"  << std::endl;
		(void)b;
		return ;
	}
	catch (std::exception &e) {}
	try
	{
		C &c = dynamic_cast<C&>(p); //em caso de falha, ele lança uma exceção do tipo std::bad_cast.
		std::cout << "It's an C class" << std::endl;
		(void)c;
	}
	catch (std::exception &e) 
	{
		std::cout << "It's a invalid class"  << std::endl;
	}
}