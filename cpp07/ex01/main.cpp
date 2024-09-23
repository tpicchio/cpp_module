/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:35:51 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/20 11:39:22 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void increment(int *i)
{
	(*i)++;
}

int main()
{
	int array[] = {1, 2, 3, 4, 5};

	iter(array, 5, increment);
	for (int i = 0; i < 5; i++)
		std::cout << array[i] << std::endl;
	return 0;
}
