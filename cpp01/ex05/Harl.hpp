/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:42:18 by tpicchio          #+#    #+#             */
/*   Updated: 2024/08/28 11:48:38 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
	private:
		std::string	_name;
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		Harl(std::string name);
		~Harl(void);
		void complain(std::string level);

};

#endif