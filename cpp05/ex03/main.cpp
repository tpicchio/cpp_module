/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:39:58 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/17 17:47:03 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
    Intern overworkingIntern;
    AForm* rrf;

    rrf = overworkingIntern.makeForm("robotomy request", "Mario");
    delete rrf;
    rrf = overworkingIntern.makeForm("presidential pardon", "Luigi");
    delete rrf;
    rrf = overworkingIntern.makeForm("shrubbery creation", "Peach");
    delete rrf;
    rrf = overworkingIntern.makeForm("unknown form", "Bowser");
    delete rrf;
    return 0;
}
