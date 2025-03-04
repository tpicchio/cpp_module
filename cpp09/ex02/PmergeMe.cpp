/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:19:29 by tpicchio          #+#    #+#             */
/*   Updated: 2024/10/09 15:57:30 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _v(), _d()
{
}

PmergeMe::PmergeMe(std::vector<int> v1, std::deque<int> d1) : _v(v1), _d(d1)
{
}

PmergeMe::PmergeMe(const PmergeMe &copy) : _v(copy._v), _d(copy._d)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		_v = copy._v;
		_d = copy._d;
	}
	return (*this);
}

void PmergeMe::errorCheck(std::vector<int> input)
{
	if(input.size() != _v.size())
	{
		std::cout << RED << "Error: the size of the input and output vectors are different." << RESET << std::endl;
		for (int i = 0; i < (int)_v.size(); i++)
		{
			std::cout << input[i] << " ";
		}
		std::cout << std::endl;
		return;
	}
	if(input.size() != _d.size())
	{
		std::cout << RED << "Error: the size of the input and output deques are different." << RESET << std::endl;
		for (int i = 0; i < (int)_d.size(); i++)
		{
			std::cout << input[i] << " ";
		}
		std::cout << std::endl;
		return;
	}
	for (int i = 0; i < (int)_v.size() - 1; i++)
	{
		if (_v[i] > _v[i + 1])
		{
			std::cout << RED << "Vector isn't sorted." << RESET << std::endl;
			for (int i = 0; i < (int)_v.size(); i++)
			{
				std::cout << input[i] << " ";
			}
			std::cout << std::endl;
			return;
		}
	}
	std::cout << GREEN << "Vector is sorted.\n" << RESET << std::endl;
	for (int i = 0; i < (int)_d.size() - 1; i++)
	{
		if (_d[i] > _d[i + 1])
		{
			std::cout << RED << "Deque isn't sorted." << RESET << std::endl;
			for (int i = 0; i < (int)_v.size(); i++)
			{
				std::cout << input[i] << " ";
			}
			std::cout << std::endl;
			return;
		}
	}
	std::cout << GREEN << "Deque is sorted.\n" << RESET << std::endl;
}

void PmergeMe::display(std::vector<int> input, double time_V, double time_D)
{
	// std::cout << CLEAR;
	std::cout << "Unsorted numbers:" << std::endl;
	for (int i = 0; i < (int)input.size(); i++)
	{
		std::cout << input[i] << " ";
		if(i > 15)
		{
			std::cout << "...";
			break;
		}
	}
	std::cout << "\n\nSorted numbers:" << std::endl;
	for (int i = 0; i < (int)_v.size(); i++)
	{
		std::cout << _v[i] << " ";
		if(i > 15)
		{
			std::cout << "...";
			break;
		}
	}
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(6);
	std::cout << BLUE "\nTime to process " << input.size() << " numbers with std::vector: " << time_V << "s\n" RESET;
	std::cout << YELLOW "\nTime taken to process " << input.size() << " numbers with std::deque: " << time_D << "s\n" RESET << std::endl;
	errorCheck(input);
}
