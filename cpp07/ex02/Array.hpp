/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:00:55 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/23 09:41:30 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &src);
		~Array(void);

		Array &operator=(const Array &src);

		T &operator[](unsigned int i);

		unsigned int size(void) const;

		class OutOfBoundsException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};

#include "Array.tpp"

#endif
