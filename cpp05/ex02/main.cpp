/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:04:03 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/17 17:24:21 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	checkInput()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid input" << std::endl;
		return 1;
	}
	std::cin.ignore(10000, '\n');
	return 0;
}

Bureaucrat *createBureaucrat(std::string name, int grade)
{
	try
	{
		return new Bureaucrat(name, grade);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return NULL;
	}
}

AForm *createForm(char type, std::string target)
{
	try
	{
		switch (type)
		{
			case 's':
				return new ShrubberyCreationForm(target);
			case 'p':
				return new PresidentialPardonForm(target);
			case 'r':
				return new RobotomyRequestForm(target);
			default:
				return NULL;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return NULL;
	}
}

int main()
{
	char answer = '1';
	int grade;
	Bureaucrat *bureaucrat = createBureaucrat("Tom", 150);
	if (!bureaucrat)
		return 1;
	AForm *shrubbery = createForm('s', "my_castle");
	if (!shrubbery)
	{
		delete bureaucrat;
		return 1;
	}
	AForm *presidential = createForm('p', "The new intern");
	if (!presidential)
	{
		delete bureaucrat;
		delete shrubbery;
		return 1;
	}
	AForm *robotomy = createForm('r', "The new intern");
	if (!robotomy)
	{
		delete bureaucrat;
		delete shrubbery;
		delete presidential;
		return 1;
	}
	
	std::cout << "\033[H\033[J";
	while (answer != '0')
	{
		try
		{
			std::cout << "\n" << *bureaucrat << std::endl;
			std::cout << *shrubbery << std::endl;
			std::cout << *robotomy << std::endl;
			std::cout << *presidential << std::endl;
			std::cout << "Options:\n" <<
				"1. Sign ShrubberyCreationForm\n" <<
				"2. Execute ShrubberyCreationForm\n\n" <<
				"3. Sign RobotomyRequestForm\n" <<
				"4. Execute RobotomyRequestForm\n\n" <<
				"5. Sign PresidentialPardonForm\n" <<
				"6. Execute PresidentialPardonForm\n\n" <<
				"7. Change bureaucrat's grade\n\n" <<
				"0. Exit\n\nNumber: ";
			std::cin >> answer;
			std::cin.ignore(10000, '\n');
			std::cout << "\033[H\033[J";
			switch (answer)
			{
				case '1':
					bureaucrat->signForm(*shrubbery);
					break;
				case '2':
					bureaucrat->executeForm(*shrubbery);
					break;
				case '3':
					bureaucrat->signForm(*robotomy);
					break;
				case '4':
					bureaucrat->executeForm(*robotomy);
					break;
				case '5':
					bureaucrat->signForm(*presidential);
					break;
				case '6':
					bureaucrat->executeForm(*presidential);
					break;
				case '7':
					std::cout << "\nEnter a new grade for the bureaucrat: ";
					std::cin >> grade;
					if (checkInput())
						break;
					bureaucrat->setGrade(grade);
					break;
				case '0':
					answer = '0';
					break;
				default:
					std::cout << "Invalid option" << std::endl;
					break;
			}
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	delete bureaucrat;
	delete shrubbery;
	delete presidential;
	delete robotomy;
	return 0;
}
