/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:19:29 by tpicchio          #+#    #+#             */
/*   Updated: 2024/10/04 18:17:41 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _v(), _d(), _vTime(0), _dTime(0)
{
}

PmergeMe::PmergeMe(std::vector<int> v1, std::deque<int> d1) : _v(v1), _d(d1), _vTime(0), _dTime(0)
{
	// gen_jacobsthal_sequence (_v.size());
}

PmergeMe::PmergeMe(const PmergeMe &copy) : _v(copy._v), _d(copy._d), _vTime(copy._vTime), _dTime(copy._dTime)
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
		_vTime = copy._vTime;
		_dTime = copy._dTime;
	}
	return (*this);
}

// void PmergeMe::gen_jacobsthal_sequence(int size)
// {
// 	_jacob.push_back(1);
// 	_jacob.push_back(3);
	
// }

void PmergeMe::sortVector()
{
	struct timeval start_time, end_time;
	int	struggler;

	gettimeofday(&start_time, NULL);
	if (_v.size() % 2 != 0)
	{
		struggler = _v.back();
		_v.pop_back();
	}
	sort_by_pair(1);
	for (int i = 0; i < (int)_v.size(); i++)
	{
		std::cout << _v[i] << " ";
	}
	std::cout << std::endl;
	gettimeofday(&end_time, NULL);
	this->_vTime = (end_time.tv_sec - start_time.tv_sec) 
						+ (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
}

void PmergeMe::sort_by_pair(int step)
{
	std::vector<int>::iterator first, middle, last;

	if ((step * 2) - 1 >= (int)_v.size() || step >= (int)_v.size())
		return;
	for(int i = step - 1; i + step < (int)_v.size(); i += (step * 2))
	{
		if (_v[i] > _v[i + step])
		{
			first = _v.begin() + i - (step - 1);
			middle = _v.begin() + i + 1;
			last = _v.begin() + i + step + 1;
			std::rotate(first, middle, last);
		}
	}
	sort_by_pair(step * 2);
	binary_insertion(step);
}

static int jacobsthal(int n)
{
	if(n == 0)
		return 0;

	if (n == 1)
		return 1;

	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::binary_insertion(int step)
{
	std::vector<int> chainA, chainB;
	int jacobPrev, jacobIt;
	
	for(int i = step - 1; i + step < (int)_v.size(); i += (step * 2))
	{
		chainB.push_back(_v[i]);
		chainA.push_back(_v[i + step]);
		if(i + (step * 2) < (int)_v.size() && i + (step * 3) >= (int)_v.size())
			chainB.push_back(_v[i + (step * 2) ]);
	}
	chainA.insert(chainA.begin(), chainB[0]);
	jacobPrev = 1;
	jacobIt = 3;
	for (; jacobsthal(jacobIt) < chainB.size(); jacobIt++)
	{
		
	}
}
