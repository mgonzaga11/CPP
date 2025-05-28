/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:24:46 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/28 11:58:20 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(){
	std::cout << std::endl;
	std::cout << "========================= FORM TEST  ===========================" << std::endl;
	std::cout << "=================================================================\n" << std::endl;

	try{
		std::cout << "-------------------- Too High sign grade test --------------------" << std::endl;
		Form formA("FormA_HighSign", 0, 50);
	}
	catch (std::exception & e){
		std::cout << "Exception (Sign): " << e.what() << std::endl;
	}

	try {
		std::cout << "-------------------- Too High exec grade test --------------------" << std::endl;
		Form formB("FormB_HighExec", 50, 0);
	}
	catch (std::exception & e){
		std::cout << "Exception (Exec): " << e.what() << std::endl;
	}

	try {
		std::cout << "-------------------- Too Low sign grade test ---------------------" << std::endl;
		Form formC("FormC_LowSign", 160, 50);
	}
	catch (std::exception & e){
		std::cout << "Exception (Sign): " << e.what() << std::endl;
	}

	try {
		std::cout << "-------------------- Too Low exec grade test ---------------------" << std::endl;
		Form formD("FormD_LowExec", 50, 160);
	}
	catch (std::exception & e){
		std::cout << "Exception (Exec): " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\n====================== BUREAUCRAT TEST  =========================" << std::endl;
	std::cout << "=================================================================\n" << std::endl;

	try {
		std::cout << "---------------------- Bureaucrat can sign -----------------------" << std::endl;
		Bureaucrat alice("Alice", 10);
		Form contract("Contract", 15, 5);
		std::cout << alice << std::endl;
		std::cout << contract << std::endl;
		std::cout << "Bureaucrat " << alice.getName() << " tries to sign the form " << contract.GetName() << std::endl;
		alice.signForm(contract);
		std::cout << "\n" << std::endl;
	}
	catch (std::exception & e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "--------------------- Bureaucrat cannot sign ---------------------" << std::endl;
		Bureaucrat bob("Bob", 100);
		Form report("Report", 90, 30);
		std::cout << bob << std::endl;
		std::cout << report << std::endl;
		std::cout << "Bureaucrat " << bob.getName() << " tries to sign the form " << report.GetName() << std::endl;
		bob.signForm(report);
		std::cout << "\n" << std::endl;
	}
	catch (std::exception & e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
