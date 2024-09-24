/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:42:55 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/23 15:16:39 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>


int main()
{
	Span sp = Span(5);

	sp.addNumber(5);
	try{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		sp.addNumber(1);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	Span sp2 = Span(10000);
	std::vector<int> v;
	std::srand(static_cast<unsigned int>(std::time(0)));
	for (int i = 0; i < 1000000; i++)
	{
		v.push_back(i);
	}
	std::random_shuffle(v.begin(), v.end());
	try{
		sp2.addNumber(v.begin(), v.begin() + 10000);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}