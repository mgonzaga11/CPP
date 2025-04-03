/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:45:56 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/16 15:47:28 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "The program must receive 3 parameters: <filename> <string1> <string2>" << std::endl;
		return 1;
	}

	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::stringstream name_file;
	std::ifstream oldfile(argv[1]);

	if (!oldfile) {
		std::cerr << "Error: Could not open file " << argv[1] << std::endl;
		return 1;
	}
	name_file << argv[1] << ".replace";
	std::ofstream newfile(name_file.str().c_str());
	if (!newfile) {
		std::cerr << "Error: Could not create file " << name_file.str() << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(oldfile, line)) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		newfile << line << '\n';
	}
	oldfile.close();
	newfile.close();
	return 0;
}