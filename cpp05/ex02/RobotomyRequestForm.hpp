/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:53:58 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/17 16:49:59 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

		void execute(Bureaucrat const &executor) const;

		
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &rhs);

#endif
