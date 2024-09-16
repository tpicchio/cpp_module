/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:11:36 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/10 12:47:03 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->firstname = "";
	this->lastname = "";
	this->nickname = "";
	this->phone_number = "";
	this->secret = "";
}

Contact::~Contact(void)
{
	std::cout << "Contact destroyed" << std::endl;
}

std::string	Contact::trimAndReplaceStr(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] < 32 || str[i] > 126)
			str[i] = ' ';
	}
	while (str[0] == ' ')
		str.erase(0, 1);
	while (str[str.length() - 1] == ' ')
		str.erase(str.length() - 1, 1);
	return (str);
}

int	Contact::isValidStr(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
			return (1);
	}
	return (0);
}

void	Contact::setFirstname(void)
{
	std::string	str;

	std::cout << "Enter the first name of the contact:\n";
	do
	{
		std::cout << "> ";
		std::getline(std::cin, str);
		str = this->trimAndReplaceStr(str);
	}while (str.empty() || this->isValidStr(str) == 0);
	this->firstname = str;
}

void	Contact::setLastname(void)
{
	std::string	str;

	std::cout << "Enter the last name of the contact:\n";
	do
	{
		std::cout << "> ";
		std::getline(std::cin, str);
		str = this->trimAndReplaceStr(str);
	}while (str.empty() || this->isValidStr(str) == 0);
	this->lastname = str;
}

void	Contact::setNickname(void)
{
	std::string	str;

	std::cout << "Enter the nickname of the contact:\n";
	do
	{
		std::cout << "> ";
		std::getline(std::cin, str);
		str = this->trimAndReplaceStr(str);
	}while (str.empty() || this->isValidStr(str) == 0);
	this->nickname = str;
}

void	Contact::setPhoneNumber(void)
{
	std::string	str;

	std::cout << "Enter the phone number of the contact:\n";
	do
	{
		std::cout << "> ";
		std::getline(std::cin, str);
		if (str.length() != 10)
		{
			std::cout << "Invalid phone number, try again." << std::endl;
			str.clear();
		}
		else if (str.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << "Invalid phone number, try again." << std::endl;
			str.clear();
		}
	}while (str.empty());
	this->phone_number = str;
}

void	Contact::setSecret(void)
{
	std::string	str;

	std::cout << "Enter the darkest secret of the contact:\n";
	do
	{
		std::cout << "> ";
		std::getline(std::cin, str);
	}while (str.empty());
	this->secret = str;
}

std::string	Contact::getFirstname(void)
{
	return (this->firstname);
}

std::string	Contact::getLastname(void)
{
	return (this->lastname);
}

std::string	Contact::getNickname(void)
{
	return (this->nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->phone_number);
}

std::string	Contact::getSecret(void)
{
	return (this->secret);
}
