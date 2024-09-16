/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:03:43 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/16 10:15:40 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

int main()
{
	char answer = '0';
	Bureaucrat *b = createBureaucrat("Bob", 1);
	if (!b)
	{
		delete b;
		return 1;
	}
	Bureaucrat *c = createBureaucrat("Charlie", 150);
	if (!c)
	{
		delete b;
		delete c;
		return 1;
	}
	std::cout << "\033[H\033[J";
	while (answer != '5')
	{
		try
		{
			std::cout << *b << std::endl;
			std::cout << *c << std::endl;
			std::cout << "Options:\n1) To increment Bob's grade.\n"
					  << "2) To decrement Bob's grade.\n"
					  << "3) To increment Charlie's grade.\n"
					  << "4) To decrement Charlie's grade.\n"
					  << "5) Exit." << std::endl;
			std::cin >> answer;
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
					c->incrementGrade();
					break;				
				case '4':
					c->decrementGrade();
					break;				
				case '5':
					answer = '5';
					break;
				default:
					std::cout << "Invalid option" << std::endl;
					break;
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	delete b;
	delete c;
	return 0;
}