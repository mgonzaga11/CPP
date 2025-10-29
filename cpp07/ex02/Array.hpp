/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:10:45 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/10/22 20:25:00 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <exception>
 

template <typename T>
class Array{
	private:
		T*				array;
		unsigned int	sizeArray;

	public:
		Array(void);
		Array(Array const& that);
		Array(unsigned int n);
		~Array(void);

		Array&	operator=(Array const& that);
		T&		operator[](unsigned int i) const;

		unsigned int size(void) const;

		class outOfRange : public std::exception {
			public:
				virtual const char *what() const throw(){ 
					return ( "Error: Index out of bounds"  ); };
		};
};

template <typename T>
Array<T>::Array(): array(NULL), sizeArray(0){};

template <typename T>
Array<T>::Array(unsigned int n): array(new T[n]), sizeArray(n){};

template <typename T>
Array<T>::Array(Array const &that){
	this->sizeArray = that.sizeArray;
	if (that.array != NULL){
		this->array = new T[that.sizeArray];
		for (unsigned int i = 0; i < this->sizeArray; i++) {
				this->array[i] = that[i];
		}
	}
	else
		this->array = NULL;
}

template <typename T>
Array<T>::~Array(void) {
	delete [] this->array;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &that) {
	if(this != &that){
		this->sizeArray = that.sizeArray;
		if (this->array != NULL) {
			delete[] array;
		}
		if (that.array != NULL){
			this->array = new T[this->size()];
			for (unsigned int i = 0; i < this->size(); i++) {
				this->array[i] = that[i];
			}
		}
		else
			this->array = NULL;
	}
	return *this;
}

template <typename T>
T	&Array<T>::operator[](unsigned int i) const{
	if (i >= Array<T>::sizeArray)
		throw outOfRange();
	return this->array[i];
}

template <typename T>
unsigned int	Array<T>::size(void) const{
	return(this->sizeArray);
}

#endif
