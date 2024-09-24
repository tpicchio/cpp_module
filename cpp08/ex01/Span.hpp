/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:29:54 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/24 12:32:41 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _v;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &cpy);
		~Span();
		Span &operator=(const Span &cpy);

		void addNumber(int nb);
		int shortestSpan();
		int longestSpan();
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		class FullSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NoNumberSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
