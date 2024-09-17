/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:11:01 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/17 16:46:22 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

		void execute(Bureaucrat const &executor) const;

		class FileNotOpenedException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &rhs);

#endif
