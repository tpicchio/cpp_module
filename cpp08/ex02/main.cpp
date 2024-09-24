/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:45:52 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/24 12:46:17 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <limits>
#include <cstdio>

int	checkInput()
{
	if (std::cin.eof())
	{
		std::cin.clear();
		clearerr(stdin);
		std::cout << std::endl;
		std::cout << "\033[H\033[J";
		return 1;
	}
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "\033[1;31mInvalid input" << std::endl;
		return 1;
	}
	std::cin.ignore(10000, '\n');
	return 0;
}

int main()
{
	MutantStack<int> mutant;
	char answer = '1';

	while (answer != '0')
	{
		std::cout << "\n\033[0mOptions:\n1. Push\n2. Pop\n3. Top\n4. Size\n" <<
					 "5. Begin\n6. Print\n0. Exit\nEnter option: ";
		std::cin >> answer;
		if (checkInput() == 1)
			continue;
		std::cout << "\033[H\033[J\033[1;34m";
		switch (answer)
		{
			case '1':
				int value;
				std::cout << "\033[0mEnter value: ";
				std::cin >> value;
				if (checkInput() == 1)
					continue;
				mutant.push(value);
				std::cout << "\033[1;34m\nPushed: " << value << std::endl;
				break;
			case '2':
				if (mutant.size() == 0)
					std::cout << "\nStack is empty\n";
				else{
					std::cout << "\nPopped: " << mutant.top() << std::endl;
					mutant.pop();
				}
				break;
			case '3':
				if (mutant.size() == 0)
					std::cout << "\nStack is empty\n";
				else
					std::cout << "\nTop: " << mutant.top() << std::endl;
				break;
			case '4':
				std::cout << "\nSize: " << mutant.size() << std::endl;
				break;
			case '5':
				if (mutant.size() == 0)
					std::cout << "\nStack is empty\n";
				else
					std::cout << "\nBegin: " << *mutant.begin() << std::endl;
				break;
			case '6':
				if (mutant.size() == 0)
					std::cout << "\nStack is empty\n";
				else {
					std::cout << "\nStack:\n";
					for (MutantStack<int>::iterator it = mutant.begin(); it != mutant.end(); it++)
						std::cout << *it << " ";
					std::cout << std::endl;
				}
				break;
			case '0':
				std::cout << "\n\tSubject test:\033[0m\n";
				break;
			default:
				std::cout << "\n\033[1;31mInvalid option\n";
				break;
		}
	}
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
