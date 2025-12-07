#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int	main(int ac, char **av) {

	if (ac != 2) {
		std::cerr << RED "Error: wrong numbers of arguments." \
			<< "\"[1]./btc [2] ./validInputFile.csv/txt...\"." DFT << std::endl;
		return (1);
	}

	try {
		BitcoinExchange	data("./data.csv");
		data.printFile( av[1]);
	} catch (const std::exception &e) {
		std::cerr << RED "Error: " << e.what() << DFT << std::endl;
	}

	return (0);
}
