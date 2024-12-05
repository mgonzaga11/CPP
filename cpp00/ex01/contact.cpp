/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:32:26 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/12/03 20:11:01 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void	contact::SetFirstName(std::string fn)
{
	FirstName = fn;	
}
void	contact::SetLastName(std::string ln)
{
	LastName = ln;
}
void	contact::SetNickName(std::string nm)
{
	NickName = nm;
}
void	contact::SetPhoneNumber(std::string pn)
{
	PhoneNumber = pn;
}
void	contact::SetDarkestSecret(std::string ds)
{
	DarkestSecret = ds;
}

std::string contact::GetFirstName()
{
	return(FirstName);
}
std::string contact::GetLastName()
{
	return(LastName);
}
std::string contact::GetNickName()
{
	return(NickName);
}
std::string contact::GetPhoneNumber()
{
	return(PhoneNumber);
}
std::string contact::GetDarkestSecret()
{
	return(DarkestSecret);
}

void	contact::index_number()
{
		index++;	
}

int	contact::get_index()
{
	return(index);
}