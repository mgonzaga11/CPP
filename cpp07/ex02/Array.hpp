/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:10:45 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/10/06 20:12:43 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <exception>

template <typename T>
class Array {

    private:
        T* array;
        size_t len;

    public:
        Array(void); // constructor empty array
        Array(unsigned int n); // constructor n elements array
        Array(const Array<T>& other); // copy constructor - deep copy
        Array& operator=(const Array<T>& other); // copy assignment operator - deep copy
        ~Array(void); // destructor

        T& operator[](size_t index); // [] subscript operator
        size_t size(void) const;
};

#endif
