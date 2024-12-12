/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:15:32 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/12/12 19:58:16 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class contact
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string	DarkestSecret;
	
	public:
		void	SetFirstName(std::string fn);
		void	SetLastName(std::string ln);
		void	SetNickName(std::string nm);
		void	SetPhoneNumber(std::string pn);
		void	SetDarkestSecret(std::string ds);

		
		std::string GetFirstName ();
        std::string GetLastName ();
        std::string GetNickName ();
        std::string GetPhoneNumber ();
        std::string GetDarkestSecret ();
};

#endif