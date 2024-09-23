/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:06:35 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/20 11:15:59 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void	swap(T &n1, T &n2)
{
	T	swap = n1;
	n1 = n2;
	n2 = swap;
}

template<typename T>
T		min(T	&n1, T &n2)
{
	return n1 < n2 ? n1 : n2;
}

template<typename T>
T		max(T &n1, T &n2)
{
	return n1 > n2 ? n1 : n2;
}



#endif