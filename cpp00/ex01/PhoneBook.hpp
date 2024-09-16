/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:15:29 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/10 12:35:55 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		pos;
		void	displayContact( int index );
		
	public:
		PhoneBook( void );
		~PhoneBook( void );
		void	addContact( void );
		void	searchContact( void );
		void	displayPhoneBook( void );
};

#endif