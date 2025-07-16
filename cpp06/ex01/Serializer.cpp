/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:03:20 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/07/16 18:03:21 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{	return (reinterpret_cast<uintptr_t>(ptr)); }

Data *Serializer::deserialize(uintptr_t raw)
{	return (reinterpret_cast<Data *>(raw)); }