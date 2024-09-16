/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:34:12 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/16 12:11:10 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

Form *createForm(std::string name, int grade)
{
	try
	{
		return new Form(name, grade, 150);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return NULL;
	}
}

int main()
{
	std::string name;
	char answer = '0';
	int grade;

	std::cout << "Enter a name for the bureaucrat: ";
	std::cin >> name;
	std::cout << "Enter a grade for the bureaucrat: ";
	std::cin >> grade;
	if (checkInput())
		return 1;
	Bureaucrat *b = createBureaucrat(name, grade);
	std::cout << "Enter a name for the form: ";
	std::cin >> name;
	std::cout << "Enter a grade to sign for the form: ";
	std::cin >> grade;
	if (checkInput())
		return 1;
	Form *f = createForm(name, grade);
	std::cout << "\033[H\033[J";
	while (answer != '4')
	{
		try
		{	
			std::cout << *b << std::endl;
			std::cout << *f << std::endl;
			std::cout << "Options:\n" <<
						"1. Increment bureaucrat's grade\n" <<
						"2. Decrement bureaucrat's grade\n" <<
						"3. Sign form\n4. Exit\n" << std::endl;
			std::cin >> answer;
			if (checkInput())
				return 1;
			std::cout << "\033[H\033[J";
			switch (answer)
			{
				case '1':
					b->incrementGrade();
					break;
				case '2':
					b->decrementGrade();
					break;
				case '3':
					b->signForm(*f);
					break;
				case '4':
					answer = '4';
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
	delete b;
	delete f;
	return 0;
}
