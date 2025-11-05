#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <list>
# include <stack>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) {};
		MutantStack(const MutantStack &copy){*this = copy;};
		~MutantStack(void) {};
		MutantStack	&operator=(const MutantStack &copy){
			if (this != &copy)
				std::stack<T>::operator=(copy);
			return (*this);
		}
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void){
			return (this->c.begin());
		}
		iterator	end(void){
			return (this->c.end());
		}
};

#endif