/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:19:45 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/23 11:17:31 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point v0;
	Point v1;
	Point v2;

	Point dot00;
	Point dot01;
	Point dot11;
	Point dot02;
	Point dot12;

	Point u;
	Point v;
	
	v0 = c - a;
	v1 = b - a;
	v2 = point - a;

	dot00 = v0 * v0;
	dot01 = v0 * v1;
	dot02 = v0 * v2;
	dot11 = v1 * v1;
	dot12 = v1 * v2;

	u = (dot11 * dot02  -  dot01 * dot12) / (dot00 * dot11  -  dot01 * dot01);
	v = (dot00 * dot12  -  dot01 * dot02) / (dot00 * dot11  -  dot01 * dot01);

	if (u >= 0 && v >= 0 && u + v < 1)
		return (true);
	else
		return (false);
	
}
