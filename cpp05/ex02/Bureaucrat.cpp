/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:02:22 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/17 17:10:23 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name), _grade(cpy._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this == &rhs)
		return *this;
	_grade = rhs._grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	if (form.getSigned() && form.getGradeToSign() >= _grade)
	{
		std::cout << "\033[1;34m Form " << form.getName() << " is already signed.\033[0m" << std::endl;
	}
	else if (form.getGradeToSign() >= _grade)
	{
		std::cout << "\033[1;32m" << _name << " signed " << form.getName() << ".\033[0m" << std::endl;
		form.beSigned(*this);
	}
	else
		std::cout << "\033[1;31m" << _name << " couldn’t sign " << form.getName() << " because grade is too low.\033[0m" << std::endl;
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << "\033[1;32m" << _name << " executed " << form.getName() << ".\033[0m" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "\033[1;31m" << _name << " couldn’t execute " << form.getName() << " because " << e.what() << "\033[0m" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "\033[1;31mGrade is too high\033[0m\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "\033[1;31mGrade is too low\033[0m\n";
}

