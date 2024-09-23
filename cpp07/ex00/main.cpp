/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:13:33 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/20 11:15:11 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	int	n1 = 10;
	int n2 = 20;
	char c = 'c';
	char d = 'd';

	std::cout << "n1 = " << n1 << " n2 = " << n2 << std::endl;
	swap(n1, n2);
	std::cout << "n1 = " << n1 << " n2 = " << n2 << std::endl;
	std::cout << "min(n1, n2) = " << min(n1, n2) << std::endl;
	std::cout << "max(n1, n2) = " << max(n1, n2) << std::endl;
	
	std::cout << "c = " << c << " d = " << d << std::endl;
	swap(c, d);
	std::cout << "c = " << c << " d = " << d << std::endl;
	std::cout << "min(c, d) = " << min(c, d) << std::endl;
	std::cout << "max(c, d) = " << max(c, d) << std::endl;
	return 0;
}
