/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:16:02 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/10 12:33:57 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phone_number;
		std::string	secret;
		std::string	trimAndReplaceStr(std::string str);
		int			isValidStr(std::string str);

	public:
		Contact(void);
		~Contact(void);
		void		setFirstname(void);
		void		setLastname(void);
		void		setNickname(void);
		void		setPhoneNumber(void);
		void		setSecret(void);
		std::string	getFirstname(void);
		std::string	getLastname(void);
		std::string	getNickname(void);
		std::string	getPhoneNumber(void);
		std::string	getSecret(void);
};

#endif
