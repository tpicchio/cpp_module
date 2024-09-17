/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:02:57 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/17 16:51:51 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("default", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy), _target(cpy._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this == &rhs)
		return *this;
	_target = rhs._target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	if (!getSigned())
		throw AForm::FormNotSignedException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &rhs)
{
	out << "Form name: " << rhs.getName() << std::endl;
	out << "Grade to sign: " << rhs.getGradeToSign() << std::endl;
	out << "Grade to execute: " << rhs.getGradeToExec() << std::endl;
	return out;
}
