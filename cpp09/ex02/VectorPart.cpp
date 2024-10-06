/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorPart.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:32:03 by tpicchio          #+#    #+#             */
/*   Updated: 2024/10/06 12:52:34 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::jacobsthal(int n)
{
	if(n == 0)
		return 0;

	if (n == 1)
		return 1;

	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::sortVector()
{
	int	struggler = -1;

	if (_v.size() % 2 != 0)
	{
		struggler = _v.back();
		_v.pop_back();
	}
	sort_by_pair_v(1);
	if (struggler != -1)
	{		
		std::vector<int>::iterator itInsert = std::lower_bound(_v.begin(), _v.end(), struggler);
		_v.insert(itInsert, struggler);
	}
}

void PmergeMe::sort_by_pair_v(int step)
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
	if((step * 3) - 1 >= (int)_v.size())
		return;
	sort_by_pair_v(step * 2);
	binary_insertion_v(step);
}

void PmergeMe::binary_insertion_v(int step)
{
	std::vector<int> chainA, chainB;
	std::vector<int>::iterator itInsert;
	int jacobPrev, jacobIt;
	int numAdded = 0;

	for(int i = step - 1; i + step < (int)_v.size(); i += (step * 2))
	{
		chainB.push_back(_v[i]);
		chainA.push_back(_v[i + step]);
		if(i + (step * 2) < (int)_v.size() && i + (step * 3) >= (int)_v.size())
			chainB.push_back(_v[i + (step * 2) ]);
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
		for(int j = 0; j < (int)_v.size(); j++)
		{
			if(_v[j] == chainA[i])
			{
				for(int k = j - (step - 1); k <= j; k++)
				{
					chainB.push_back(_v[k]);
				}
			}
		}
	}
	_v.clear();
	for(int i = 0; i < (int)chainB.size(); i++)
	{
		_v.push_back(chainB[i]);
	}
}
