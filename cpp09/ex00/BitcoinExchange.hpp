/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:59:42 by tpicchio          #+#    #+#             */
/*   Updated: 2024/10/02 12:43:26 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <ctime>
#include <exception>
#include <fstream>
#include <string>
#include <ostream>
#include <typeinfo>
#include <sstream>
#include <algorithm>
#include <stdlib.h>


class BitcoinExchange
{
	private:
		std::map<std::time_t, float> db;

	private:
		void fillDataBase();
		void parseInfile(const std::string &infile);
		static std::time_t isValidDate(std::string &date);
		std::pair<std::time_t, float> findByDate(std::time_t date);

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string infile);
		BitcoinExchange(BitcoinExchange &src);
		~BitcoinExchange();

		BitcoinExchange &operator=(BitcoinExchange &src);

		class DataBaseError : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class InfileError : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};


#endif