/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:19:45 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/24 10:42:33 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool sideCheck (Point const p1, Point const p2, Point const a, Point const b)
{
	Point cp1 = (b - a) * (p1 - a);
	Point cp2 = (b - a) * (p2 - a);

	if ((cp1.getX().toFloat() * cp2.getX().toFloat()) + (cp1.getY().toFloat() * cp2.getY().toFloat()) >= 0)
		return (true);
	else
		return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{

	if (sideCheck(point, a, b, c) && sideCheck(point, b, a, c) && sideCheck(point, c, a, b))
		return (true);
	else
		return (false);
}
