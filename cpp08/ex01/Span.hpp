#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <algorithm>


class Span
{
	private:
		std::vector<int>	vectorInt;
		unsigned int		size;
	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const &copy);
		Span &operator=(Span const &og);
		~Span(void);

		void addNumber(int number);
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan(void);
		int longestSpan(void);

		class FullSpanException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class NoSpanException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

#endif