/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:35:24 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/23 11:41:14 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{}

Span::Span(unsigned int n) : _n(n)
{}

Span::Span(const Span &cpy)
{
	_n = cpy._n;
	_v = cpy._v;
}

Span::~Span()
{}

Span &Span::operator=(const Span &cpy)
{
	_n = cpy._n;
	_v = cpy._v;
	return *this;
}

void Span::addNumber(int nb)
{
	if (_v.size() >= _n)
		throw FullSpanException();
	_v.push_back(nb);
}

int Span::shortestSpan()
{
	if (_v.size() <= 1)
		throw NoNumberSpanException();
	std::sort(_v.begin(), _v.end());
	int min = _v[1] - _v[0];
	for (size_t i = 1; i < _v.size(); i++)
	{
		if (_v[i] - _v[i - 1] < min)
			min = _v[i] - _v[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
	if (_v.size() <= 1)
		throw NoNumberSpanException();
	std::sort(_v.begin(), _v.end());
	return _v[_v.size() - 1] - _v[0];
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_v.size() + std::distance(begin, end) > _n)
		throw FullSpanException();
	_v.insert(_v.end(), begin, end);
}

const char *Span::FullSpanException::what() const throw()
{
	return "Error: Span is full.";
}

const char *Span::NoNumberSpanException::what() const throw()
{
	return "Error: Not enough number in Span.";
}
