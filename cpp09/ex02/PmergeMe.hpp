/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:13:03 by tpicchio          #+#    #+#             */
/*   Updated: 2024/10/06 12:39:39 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <iomanip> 

#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define BLUE "\033[1m\033[34m"
#define YELLOW "\033[1m\033[33m"
#define RESET "\033[0m"

class PmergeMe
{
	private:
		std::vector<int> _v;
		std::deque<int> _d;

	private:
		void sort_by_pair_v(int step);
		void binary_insertion_v(int step);

		void sort_by_pair_d(int step);
		void binary_insertion_d(int step);

		int jacobsthal(int n);
		
	public:
		PmergeMe();
		PmergeMe(std::vector<int> v1, std::deque<int> d1);
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &copy);
		void sortVector();
		void sortDeque();
		void display(std::vector<int> input, double time_V, double time_D);
};

#endif
