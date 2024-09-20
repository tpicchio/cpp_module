/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:17:21 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/20 09:48:01 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	(void)cpy;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cpy)
{
	(void)cpy;
	return *this;	
}

char		c = 0;
int		i = 1;
float	f = 0;
double	d = 0;

bool ScalarConverter::isChar(const std::string &str)
{
	if ((str.length() == 1 && (str[0] < '0' || str[0] > '9'))
		|| (str.length() == 3 && str[0] == '\'' && str[2] == '\''))
	{
		if (str.length() == 1)
			c = static_cast<char>(str[0]);
		else
			c = static_cast<char>(str[1]);
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
		if (c < 33 || c > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return true;
	}
	return false;
}

bool ScalarConverter::isInt(const std::string &str)
{
	size_t	cont = 0;

	if (str[0] == '-' || str[0] == '+')
		cont++;
	for (;cont < str.length(); cont++)
	{
		if (str[cont] < '0' || str[cont] > '9')
			return false;
	}
	std::stringstream intStr(str);
	intStr >> i;
	c = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	
	if (c < 33 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
	return true;
}

bool ScalarConverter::isFloat(const std::string &str)
{
	size_t	cont = 0;
	int		dot = 0;

	if (str[str.length() - 1] != 'f')
		return false;
	if (str == "+inff")
		f = INFINITY;
	else if (str == "-inff")
		f = -INFINITY;
	else if (str == "nanf")
		f = NAN;
	else
	{
		if (str[0] == '-' || str[0] == '+')
			cont++;
		if (str[cont] == '.' || str[cont] == 'f')
			return false;
		for (;cont < str.length() - 1; cont++)
		{
			if (str[cont] == '.' && dot < 1)
			{
				cont++;
				dot++;
			}
			if (str[cont] < '0' || str[cont] > '9')
				return false;
		}
		std::stringstream floatStr(str);
		floatStr >> f;
	}
	c = static_cast<char>(f);
	i = static_cast<int>(f);
	d = static_cast<double>(f);

	if (f == INFINITY || f == -INFINITY || f != f)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (c < 33 || c > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
	}
	std::cout.unsetf(std::ios::fixed);
	std::cout.precision(6);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
	return true;
}


bool ScalarConverter::isDouble(const std::string &str)
{
	size_t	cont = 0;
	int		dot = 0;

	if (str == "+inf")
		d = INFINITY;
	else if (str == "-inf")
		d = -INFINITY;
	else if (str == "nan")
		d = NAN;
	else
	{
		if (str[0] == '-' || str[0] == '+')
			cont++;
		if (str[cont] == '.')
			return false;
		for (;cont < str.length(); cont++)
		{
			if (str[cont] == '.' && dot < 1)
			{
				cont++;
				dot++;
			}
			if (str[cont] < '0' || str[cont] > '9')
				return false;
		}
		std::stringstream doubleStr(str);
		doubleStr >> d;
	}
	c = static_cast<char>(d);
	i = static_cast<int>(d);
	f = static_cast<double>(d);
	if (d == INFINITY || d == -INFINITY || d != d)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (c < 33 || c > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
	}
	std::cout.unsetf(std::ios::fixed);
	std::cout.precision(6);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
	return true;
}

void	ScalarConverter::convert(std::string str)
{
	std::cout << "Input: " << str << std::endl << std::endl;
	if (isChar(str))
		return;
	else if (isInt(str))
		return;
	else if (isFloat(str))
		return;
	else if (isDouble(str))
		return;

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" <<  std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
