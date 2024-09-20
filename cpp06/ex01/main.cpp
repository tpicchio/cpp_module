/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:12:16 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/20 10:12:23 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;
	data.s1 = "Hello";
	data.n = 42;
	data.s2 = "World";

	uintptr_t ptr = Serializer::serialize(&data);
	Data* newData = Serializer::deserialize(ptr);

	std::cout << "s1: " << newData->s1 << std::endl;
	std::cout << "n: " << newData->n << std::endl;
	std::cout << "s2: " << newData->s2 << std::endl;

	return 0;
}
