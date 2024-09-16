/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:51:52 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/13 12:49:20 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed z = (b.getX() - a.getX()) * (point.getY() - a.getY())
			- (b.getY() - a.getY()) * (point.getX() - a.getX());
	Fixed z1 = (c.getX() - b.getX()) * (point.getY() - b.getY())
			- (c.getY() - b.getY()) * (point.getX() - b.getX());
	Fixed z2 = (a.getX() - c.getX()) * (point.getY() - c.getY())
			- (a.getY() - c.getY()) * (point.getX() - c.getX());

	if ((z > 0 && z1 > 0 && z2 > 0) || (z < 0 && z1 < 0 && z2 < 0))
		return true;
	return false;
}