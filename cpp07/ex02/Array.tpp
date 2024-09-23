/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:02:29 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/23 09:39:38 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array &src) : _array(new T[src._size]()), _size(src._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
}

template <typename T>
Array<T>::~Array(void) { delete[] _array; }

template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
	if (this == &src)
		return *this;
	delete[] _array;
	_array = new T[src._size]();
	_size = src._size;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw OutOfBoundsException();
	return _array[i];
}

template <typename T>
unsigned int Array<T>::size(void) const { return _size; }

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return "Array: index out of bounds";
}

#endif
