/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:22:10 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/16 12:34:45 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExec;

	public:
		Form(void);
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form &cpy);
		~Form();

		Form &operator=(const Form &rhs);

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		void beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);

#endif