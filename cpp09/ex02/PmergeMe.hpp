/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:13:03 by tpicchio          #+#    #+#             */
/*   Updated: 2024/10/04 17:57:30 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sys/time.h>

#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define RESET "\033[0m"

class PmergeMe
{
	private:
		std::vector<int> _v;
		std::deque<int> _d;
		std::vector<int> _jacob;
		double _vTime;
		double _dTime;

	private:
		void sort_by_pair(int step);
		void binary_insertion(int step);
		// void gen_jacobsthal_sequence(int size);
		
	public:
		PmergeMe();
		PmergeMe(std::vector<int> v1, std::deque<int> d1);
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &copy);
		void sortVector();
		void sortDeque();
		void display();
};

#endif
