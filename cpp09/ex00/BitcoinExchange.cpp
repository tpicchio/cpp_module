/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:01:18 by tpicchio          #+#    #+#             */
/*   Updated: 2024/10/02 13:35:42 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	this->fillDataBase();
}

BitcoinExchange::BitcoinExchange(const std::string infile)
{
	this->fillDataBase();
	this->parseInfile(infile);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &src) : db(src.db)
{}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &src)
{
	if (this != &src)
	{
		std::swap(this->db, src.db);
	}
	return *this;
}

void BitcoinExchange::fillDataBase()
{
	std::ifstream file("data.csv");
	if (!file.is_open() || !file.good())
	{
		std::cerr << "Error: can't open database infile." << std::endl;
		throw BitcoinExchange::DataBaseError();
	}
	std::string line;
	int i = 0;
	while (std::getline(file, line) && ++i)
	{
		if (line == "date,exchange_rate")
			continue;
		std::string date = line.substr(0, line.find(","));
		std::time_t t;
		try
		{
			t = isValidDate(date);
		}
		catch (std::exception &e)
		{
			std::cerr << "Wrong date at line: " << i << " in file: data.csv" << std::endl;
			throw BitcoinExchange::DataBaseError();
		}
		std::string value = line.substr(line.find(",") + 1);
		char *end;
		float v = std::strtof(value.c_str(), &end);
		if (end == value.c_str() || *end != '\0')
		{
			std::cerr << "Error: invalid exchange rate at line: " << i << " in file: data.csv" << std::endl;
			throw BitcoinExchange::DataBaseError();
		}
		this->db[t] = v;
	}
}

std::time_t BitcoinExchange::isValidDate(std::string &dateStr)
{
	std::tm date = {};

	if (strptime(dateStr.c_str(), "%Y-%m-%d", &date) == NULL)
	{
		std::cerr << "Error: invalid date format in file." << std::endl;
		throw BitcoinExchange::DataBaseError();
	}
	std::string dayStr = dateStr.substr(dateStr.rfind("-") + 1);
	for (size_t i = 0; i < dayStr.size(); i++)
	{
		if (dayStr[i] == ' ')
			break;
		if (!std::isdigit(dayStr[i]))
		{
			std::cerr << "Error: invalid day." << std::endl;
			throw BitcoinExchange::DataBaseError();
		}
	}
	int day;
	std::stringstream intStr(dayStr);
	intStr >> day;
	if (day > 31 || day < 1)
	{
		std::cerr << "Error: invalid day." << std::endl;
		throw BitcoinExchange::DataBaseError();
	}

	// check for valid day
	if (date.tm_mon + 1 == 4 || date.tm_mon + 1 == 6
		|| date.tm_mon + 1 == 9 || date.tm_mon + 1 == 11)
	{
		if (date.tm_mday > 30)
		{
			std::cerr << "Error: invalid day for this month." << std::endl;
			throw BitcoinExchange::DataBaseError();
		}
	}

	// check for leap year
	if (date.tm_mon + 1 == 2)
	{
		if ((date.tm_year + 1900) % 4 == 0)
		{
			if (date.tm_mday > 29)
			{
				std::cerr << "Error: invalid day for this month." << std::endl;
				throw BitcoinExchange::DataBaseError();
			}
		}
		else
		{
			if (date.tm_mday > 28)
			{
				std::cerr << "Error: invalid day for this month." << std::endl;
				throw BitcoinExchange::DataBaseError();
			}
		}
	}
	return mktime(&date);
}

void BitcoinExchange::parseInfile(const std::string &infile)
{
	std::ifstream file(infile.c_str());
	if (!file.is_open() || !file.good())
	{
		std::cerr << "Error: can't open infile." << std::endl;
		throw BitcoinExchange::InfileError();
	}
	if (db.empty())
	{
		std::cerr << "Error: database is empty." << std::endl;
		throw BitcoinExchange::InfileError();
	}
	std::string line;
	while (std::getline(file, line))
	{
		if (line == "date | value")
			continue;
		std::string date = line.substr(0, line.find("|"));
		std::time_t t;
		try
		{
			t = isValidDate(date);
		}
		catch (std::exception &e)
		{
			continue;
		}
		std::string value = line.substr(line.find("|") + 1);
		char *end;
		float v = std::strtof(value.c_str(), &end);
		if (end == value.c_str() || *end != '\0')
		{
			std::cerr << "Error: bad input => " << value << std::endl;
			continue;
		}
		if (v < 0.0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (v > 1000.0)
		{
			std::cerr << "Error: number too big." << std::endl;
			continue;
		}
		try
		{
			std::pair<std::time_t, float> p = findByDate(t);
			std::cout << date << " => " << v << " = " << p.second * v << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: can't find date in database." << std::endl;
		}
	}
}

std::pair<std::time_t, float> BitcoinExchange::findByDate(std::time_t date)
{
	std::map<std::time_t, float>::iterator it = db.find(date);
	if (it != db.end())
		return std::make_pair(it->first, it->second);
	it = db.lower_bound(date);
	if (it == db.begin())
		throw BitcoinExchange::InfileError();
	--it;
	return std::make_pair(it->first, it->second);
}

const char *BitcoinExchange::DataBaseError::what() const throw()
{
	return "Could not fill database.";
}

const char *BitcoinExchange::InfileError::what() const throw()
{
	return "Infile error.";
}
