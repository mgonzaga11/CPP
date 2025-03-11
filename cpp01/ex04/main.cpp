/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:45:56 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/09 16:46:58 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "The program must receive 3 parameters: <filename> <string1> <string2>" << std::endl;
		return 1;
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::stringstream name_file;
	std::ifstream	oldfile(argv[1]);
	name_file << argv[1] << ".replace";
	if (!oldfile) {
		std::cout << "error: Open " << argv[1] << " is not possible." << std::endl;
	}
	std::ofstream	newfile(name_file.str().c_str());
	if (!newfile) {
		std::cout << "error: Open " << name_file.str() << " is not possible." << std::endl;
	}
	std::string	line;
	while (std::getline(oldfile, line)) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		newfile << line << '\n';
	}
}