/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:46:16 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/17 16:51:31 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("default", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy), _target(cpy._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this == &rhs)
		return *this;
	_target = rhs._target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	const std::string filename = (_target + "_shrubbery");
	if (executor.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	if (!getSigned())
		throw AForm::FormNotSignedException();
	std::ofstream file;
	file.open(filename.c_str(), std::ios::app);
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      \n\n" << std::endl;
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      \n\n" << std::endl;
	
	file.close();
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &rhs)
{
	out << "Form name: " << rhs.getName() << std::endl;
	out << "Grade to sign: " << rhs.getGradeToSign() << std::endl;
	out << "Grade to execute: " << rhs.getGradeToExec() << std::endl;
	return out;
}

const char *ShrubberyCreationForm::FileNotOpenedException::what() const throw()
{
	return "File not opened";
}

