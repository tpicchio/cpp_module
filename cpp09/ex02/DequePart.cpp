/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequePart.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:33:58 by tpicchio          #+#    #+#             */
/*   Updated: 2024/10/06 15:44:55 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


void PmergeMe::sortDeque()
{
	int	struggler = -1;

	if (_d.size() % 2 != 0)
	{
		struggler = _d.back();
		_d.pop_back();
	}
	sort_by_pair_d(1);
	if (struggler != -1)
	{		
		std::deque<int>::iterator itInsert = std::lower_bound(_d.begin(), _d.end(), struggler);
		_d.insert(itInsert, struggler);
	}
}

void PmergeMe::sort_by_pair_d(int step)
{
	std::deque<int>::iterator first, middle, last;

	if ((step * 2) - 1 >= (int)_d.size() || step >= (int)_d.size())
		return;
	for(int i = step - 1; i + step < (int)_d.size(); i += (step * 2))
	{
		if (_d[i] > _d[i + step])
		{
			first = _d.begin() + i - (step - 1);
			middle = _d.begin() + i + 1;
			last = _d.begin() + i + step + 1;
			std::rotate(first, middle, last);
		}
	}
	if((step * 3) - 1 >= (int)_d.size())
		return;
	sort_by_pair_d(step * 2);
	binary_insertion_d(step);
}

void PmergeMe::binary_insertion_d(int step)
{
	std::deque<int> chainA, chainB;
	std::deque<int>::iterator itInsert;
	int jacobPrev, jacobIt;
	int numAdded = 0;

	for(int i = step - 1; i + step < (int)_d.size(); i += (step * 2))
	{
		chainB.push_back(_d[i]);
		chainA.push_back(_d[i + step]);
		if(i + (step * 2) < (int)_d.size() && i + (step * 3) >= (int)_d.size())
			chainB.push_back(_d[i + (step * 2) ]);
	}
	chainA.insert(chainA.begin(), chainB[0]);
	numAdded++;
	jacobIt = jacobsthal(2);
	jacobPrev = 0;
	while (1)
	{
		jacobIt = jacobsthal(jacobIt + 2) - 1;
		if(jacobIt >= (int)chainB.size())
		{
			for (int j = jacobPrev + 1; j < (int)chainB.size(); j++)
			{
				itInsert = std::lower_bound(chainA.begin(), chainA.end(), chainB[j]);
				chainA.insert(itInsert, chainB[j]);
				numAdded++;
			}
			break;
		}
		itInsert = std::lower_bound(chainA.begin(), chainA.begin() + jacobIt + numAdded, chainB[jacobIt]);
		chainA.insert(itInsert, chainB[jacobIt]);
		numAdded++;
		for (int j = jacobIt - 1; j > jacobPrev; j--)
		{
			itInsert = std::lower_bound(chainA.begin(), chainA.begin() + j + numAdded, chainB[j]);
			chainA.insert(itInsert, chainB[j]);
			numAdded++;
		}
		jacobPrev = jacobIt;
	}
	chainB.clear();
	for(int i = 0; i < (int)chainA.size(); i++)
	{
		for(int j = 0; j < (int)_d.size(); j++)
		{
			if(_d[j] == chainA[i])
			{
				for(int k = j - (step - 1); k <= j; k++)
				{
					chainB.push_back(_d[k]);
				}
				if(j + step >= (int)_d.size())
				{
					numAdded = j + 1;
					break;
				}
			}
		}
	}
	for(int i = numAdded; i < (int)_d.size(); i++)
	{
		chainB.push_back(_d[i]);
	}
	_d.clear();
	for(int i = 0; i < (int)chainB.size(); i++)
	{
		_d.push_back(chainB[i]);
	}
}
