/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:28:53 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/17 17:31:13 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Because filling out forms is annoying enough, it would be cruel to ask our bureaucrats
to do this all day long. Fortunately, interns exist. In this exercise, you have to implement
the Intern class. The intern has no name, no grade, no unique characteristics. The only
thing the bureaucrats care about is that they do their job.
However, the intern has one important capacity: the makeForm() function. It takes
two strings. The first one is the name of a form and the second one is the target of the
form. It return a pointer to a Form object (whose name is the one passed as parameter)
whose target will be initialized to the second parameter.
It will print something like:
Intern creates <form>
If the form name passed as parameter doesn’t exist, print an explicit error message
You must avoid unreadable and ugly solutions like using a if/elseif/else forest. This
kind of things won’t be accepted during the evaluation process*/

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        AForm *_form;

    public:
        Intern(void);
        Intern(const Intern &cpy);
        ~Intern();

        Intern &operator=(const Intern &rhs);

        AForm *makeForm(std::string form, std::string target);
};

#endif