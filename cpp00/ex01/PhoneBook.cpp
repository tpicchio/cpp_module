/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:11:57 by tpicchio          #+#    #+#             */
/*   Updated: 2024/08/24 10:38:14 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->pos = -1;
	std::cout << "PhoneBook by tpicchio" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destroyed" << std::endl;
}

void	PhoneBook::addContact(void)
{
	std::string str;

	std::cout << "\033[H\033[J";
	if (this->pos == -1)
		this->pos = 0;
	if (this->pos == 8)
	{
		std::cout << "You reachead the limit of 8 contacts, from now on the oldest will be overwritten.\n";
		std::cout << "Do you want to continue? s/n\n> ";
		std::getline(std::cin, str);
		if (str != "s")
			return ;
		this->pos = 0;
	}
	this->contacts[this->pos].setFirstname();
	this->contacts[this->pos].setLastname();
	this->contacts[this->pos].setNickname();
	this->contacts[this->pos].setPhoneNumber();
	this->contacts[this->pos].setSecret();
	this->pos++;
}

void	PhoneBook::searchContact(void)
{
	int			index;
	std::string	str;

	if (this->pos == -1)
	{
		std::cout << "\033[H\033[J";
		std::cout << "No contacts available." << std::endl;
		std::cout << "You can add one with the ADD command." << std::endl;
		std::cout << "Press enter to continue." << std::endl;
		std::cin.ignore();
		return ;
	}
	std::cout << "\033[H\033[J";
	this->displayPhoneBook();
	std::cout << "Enter the index of the contact you want to display:\n";
	do
	{
		std::cout << "> ";
		std::getline(std::cin, str);
		if (str.length() != 1 || str[0] < '1' || str[0] > '8')
			std::cout << "Invalid index, try again." << std::endl;
	} while (str.length() != 1 || str[0] < '1' || str[0] > '8');
	index = (str[0] - '0') - 1;
	if (this->contacts[index].getFirstname().empty())
	{
		std::cout << "No contact at this index." << std::endl;
		std::cout << "Press enter to continue." << std::endl;
		std::cin.ignore();
		return ;
	}
	std::cout << "\033[H\033[J";
	std::cout << "\t\tCONTACT INFO" << std::endl;
	std::cout << "First name: " << this->contacts[index].getFirstname() << std::endl;
	std::cout << "Last name: " << this->contacts[index].getLastname() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[index].getSecret() << std::endl;
	std::cout << "Press enter to continue." << std::endl;
	std::cin.ignore();
}

void	PhoneBook::displayPhoneBook(void)
{
	int	i;

	i = 0;
	std::cout << "\033[H\033[J";
	std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME|PHONE NUMB|" << std::endl;
	while (i < 8)
	{
		std::cout << "         " << i + 1 << "|";
		if (this->contacts[i].getFirstname().empty())
			std::cout << "          |          |          |          |" << std::endl;
		else
			this->displayContact(i);
		i++;
	}
}

void	PhoneBook::displayContact(int index)
{
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phone_number;

	firstname = this->contacts[index].getFirstname();
	lastname = this->contacts[index].getLastname();
	nickname = this->contacts[index].getNickname();
	phone_number = this->contacts[index].getPhoneNumber();
	if (firstname.length() > 10)
	{
		firstname.resize(9);
		firstname += ".";
	}
	if (lastname.length() > 10)
	{
		lastname.resize(9);
		lastname += ".";
	}
	if (nickname.length() > 10)
	{
		nickname.resize(9);
		nickname += ".";
	}
	if (phone_number.length() > 10)
	{
		phone_number.resize(9);
		phone_number += ".";
	}
	for (int i = 0; i < 10 - (int)firstname.length(); i++)
		std::cout << " ";
	std::cout << firstname;
	std::cout << "|";
	for (int i = 0; i < 10 - (int)lastname.length(); i++)
		std::cout << " ";
	std::cout << lastname;
	std::cout << "|";
	for (int i = 0; i < 10 - (int)nickname.length(); i++)
		std::cout << " ";
	std::cout << nickname;
	std::cout << "|";
	for (int i = 0; i < 10 - (int)phone_number.length(); i++)
		std::cout << " ";
	std::cout << phone_number;
	std::cout << "|";
	std::cout << std::endl;
}
