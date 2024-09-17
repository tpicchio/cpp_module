/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:33:28 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/17 18:00:33 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern &cpy)
{
    (void)cpy;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &rhs)
{
    (void)rhs;
    return *this;
}

AForm *Intern::makeForm(std::string form, std::string target)
{
    AForm *ret;
    std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    int i = 0;

    while (i < 3)
    {
        if (form == forms[i])
            break;
        i++;
    }
    switch (i)
    {
        case 0:
            std::cout << "\033[1;32mIntern creates: \033[0m" << std::endl;
            ret = new RobotomyRequestForm(target);
            std::cout << *ret;
            std::cout << "Target: " << target << std::endl << std::endl;
            return ret;
        case 1:
            std::cout << "\033[1;32mIntern creates: \033[0m" << std::endl;
            ret = new PresidentialPardonForm(target);
            std::cout << *ret;
            std::cout << "Target: " << target << std::endl << std::endl;
            return ret;
        case 2:
            std::cout << "\033[1;32mIntern creates: \033[0m" << std::endl;
            ret = new ShrubberyCreationForm(target);
            std::cout << *ret;
            std::cout << "Target: " << target << std::endl << std::endl;
            return ret;
        default:
            std::cout << "\033[1;31mForm type not found\033[0m" << std::endl << std::endl;
            break;
    }
    return NULL;
}


