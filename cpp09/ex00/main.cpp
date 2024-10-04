/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:28:05 by tpicchio          #+#    #+#             */
/*   Updated: 2024/10/02 13:39:36 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Bad number of argument.\nUsage: ./btc <input file>\n", 1);
	else
	{
		try
		{
			BitcoinExchange btc(av[1]);
		}
		catch(std::exception &e)
		{
			std::cout << "Btc exception: " << e.what() << std::endl;
			return 1;
		}
	}
	return 0;
}
