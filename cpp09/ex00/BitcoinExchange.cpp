# include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstring>

BitcoinExchange::BitcoinExchange(void) : _file(   "./data.csv") {
	setData();
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) {
	*this = other;
}

BitcoinExchange::BitcoinExchange(std::string const &file) {
	_file = file;
	setData();
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &other) {
	if (this != &other) {
		_data = other._data;
		_file = other._file;
	}
	return (*this);
}

bool	BitcoinExchange::validateDate(std::string const &date) const {

	int	year, moth, day;

	if (sscanf(date.c_str(), "%d-%d-%d", &year, &moth, &day) != 3) {
		return (false);
	}

	if (moth < 1 || moth > 12) {
		return (false);
	}

	if (year < 2009 || year > 2024) {
		return (false);
	}

	bool	isLeapYear = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);

	int	daysInMoths[] = {31, ((isLeapYear) ? 29 : 28), 31, 30, \
		31, 30, 31, 31, 30, 31, 30, 31};

	if (day < 1 || day > daysInMoths[moth - 1]) {
		return (false);
	}

	return (true);
}

bool	BitcoinExchange::validateInput(std::string const &input) const {
	if (input.length() < 14) {
		return (false);
	}
	if (input[4] != '-' || input[7] != '-' || input[10] != ' ' \
		|| input[11] != '|' || input[12] != ' ') {
		return (false);
	}
	int	year, moth, day;
	float	value;
	char	extra;
	if (sscanf(input.c_str(), "%d-%d-%d | %f%c", &year, &moth, &day, &value, \
		&extra) != 4) {
		return (false);
	}
	if (year == 2009 && moth == 1 && day == 1) {
		return (false);
	}

	std::size_t	space = input.find(' ');
	std::string	date = input.substr(0, space);
	if (validateDate(date) == false) {
		return (false);
	}
	return (true);
}

void	BitcoinExchange::setData(void) {

	if (std::strcmp(_file.c_str(), "./data.csv")) {
		throw std::runtime_error("not found data file: " + _file);
	}

	std::ifstream	dataFile(_file.c_str());

	if (!dataFile) {
		throw std::runtime_error("could not open file.");
	}

	std::string	firstLine;
	std::getline(dataFile, firstLine);

	if (strcmp(firstLine.c_str(),"date,exchange_rate")) {
		throw std::runtime_error("Wrong fields.");
	}

	std::string	line;

	while (std::getline(dataFile, line)) {
		if (line == firstLine) {
			continue ; 
		} else {
			std::size_t	commaPos = line.find(',');
			std::string	key = line.substr(0, commaPos);
			std::string	value = line.substr(commaPos + 1, std::string::npos);
			float	valuef = atof(value.c_str());
			_data[key] = valuef;
		}
	}
	dataFile.close();
}

void	BitcoinExchange::printData(void) const {
	for (std::map<std::string, float>::const_iterator it = _data.begin(); \
	it != _data.end(); ++it) {
            std::cout << "Data: " << it->first << ", Value: " << it->second \
			<< std::fixed << std::setprecision(2) << std::endl;
        }
}

float	BitcoinExchange::findValue(std::string const &key) const {
	std::map<std::string, float>::const_iterator	it;

	it = _data.lower_bound(key);

	if (key != it->first) {
		--it;
	}
	return (it->second);
}

float	BitcoinExchange::convertBitcoin(std::string const &date, \
										float const &valueInput) {
	if (valueInput > 1000) {
		throw std::runtime_error( "too large a number." );
	} else if (valueInput < 0) {
		throw std::runtime_error( "not a positive number." );
	}
	
	if (valueInput == 0) {
		return (valueInput);
	}

	float	value = findValue(date);
	float	convertedValue = value * valueInput; 

	return (convertedValue);
}

void	BitcoinExchange::printExchange(std::string const &input) {

	if (validateInput(input) == false) {
		std::string	err =  "bad input => " + input;
		throw std::runtime_error(      err.c_str() );
	}
	std::size_t	space = input.find(' ');
	std::string	date = input.substr(0, space);
	std::string	valueInput = input.substr(input.find('|') + 2, std::string::npos);

	float	valueInputf = atof(valueInput.c_str());
	float	convertedValue = convertBitcoin(date, valueInputf);

	std::cout <<  date  ;
	std::cout <<  " => " ;
	std::cout  << valueInput;
	std::cout << " = " ;
	std::cout << convertedValue << std::fixed << std::setprecision(2);
	std::cout << std::endl;
}

void	BitcoinExchange::printFile(std::string const &fileName) {
	std::ifstream	file(   fileName.c_str());

	if (!file) {
		throw std::runtime_error( "could not open file." );
	}

	std::string line;
	std::string firstLine;
	getline(file, firstLine);

	if (strcmp(firstLine.c_str(), "date | value")) {
		throw std::runtime_error( "wrong field. \"date | value\"" );
	}

	while (std::getline(file, line)) {
		if (line == firstLine) {
			continue;
		}
		try {
			printExchange(line);
		} catch (const std::exception &e) {
			std::cerr <<  "Error: " << e.what() <<  std::endl;
		}
	}
	file.close();
}