/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:01:40 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/17 16:51:02 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("default", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy), _target(cpy._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this == &rhs)
		return *this;
	_target = rhs._target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	if (!getSigned())
		throw AForm::FormNotSignedException();
	std::cout << "*drilling noises*" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &rhs)
{
	out << "Form name: " << rhs.getName() << std::endl;
	out << "Grade to sign: " << rhs.getGradeToSign() << std::endl;
	out << "Grade to execute: " << rhs.getGradeToExec() << std::endl;
	return out;
}

