
#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
# include <map>
# include <string>

class	BitcoinExchange {

private:
	std::map<std::string, float>	_data;
	std::string						_file;

	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &other);

	BitcoinExchange	&operator=(BitcoinExchange const &other);

	void	setData(void);
	bool	validateDate(std::string const &date) const;
	float	convertBitcoin(std::string const &date, float const &valueInput);
	void	printExchange(std::string const &input);
	bool	validateInput(std::string const &input) const;
	float	findValue(std::string const &key) const;
	void	printData(void) const;

public:
	~BitcoinExchange(void);
	BitcoinExchange(std::string const &file);

	void	printFile(std::string const &file);
};

#endif