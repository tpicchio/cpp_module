/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 09:55:41 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/13 10:14:58 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{}

Fixed::Fixed(const Fixed &src) {
	*this = src;
}

Fixed::Fixed(const int value) {
	this->_value = value << this->_fractional_bits;
}

Fixed::Fixed(const float value) {
	this->_value = roundf(value * (1 << this->_fractional_bits));
}

Fixed::~Fixed(void) {
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	this->_value = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat(void) const {
	return (float)this->_value / (1 << this->_fractional_bits);
}

int Fixed::toInt(void) const {
	return this->_value >> this->_fractional_bits;
}

Fixed Fixed::operator+(const Fixed &rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	if (rhs.toFloat() == 0)
	{
		std::cout << "Division by 0, returning 0 by default." << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++(void) {
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--(void) {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

bool Fixed::operator>(const Fixed &rhs) const {
	return this->toFloat() > rhs.toFloat();
}

bool Fixed::operator<(const Fixed &rhs) const {
	return this->toFloat() < rhs.toFloat();
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return this->toFloat() >= rhs.toFloat();
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return this->toFloat() <= rhs.toFloat();
}

bool Fixed::operator==(const Fixed &rhs) const {
	return this->toFloat() == rhs.toFloat();
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return this->toFloat() != rhs.toFloat();
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return a > b ? a : b;
}

std::ostream &operator<<(std::ostream &o, const Fixed &rhs) {
	o << rhs.toFloat();
	return o;
}

std::istream &operator>>(std::istream &i, Fixed &rhs) {
	float tmp;
	i >> tmp;
	rhs = Fixed(tmp);
	return i;
}
