/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:46:49 by tpicchio          #+#    #+#             */
/*   Updated: 2024/08/28 11:51:45 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl("Harl");
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WRONG_LEVEL");
	harl.complain("WARNING");
	harl.complain("ERROR");
	return (0);
}
