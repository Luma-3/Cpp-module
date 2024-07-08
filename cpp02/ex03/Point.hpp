/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:32 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/08 13:52:07 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:

	Fixed x;
	Fixed y;

public:

// Coplien
	Point();
	Point(const Point &other);
	Point& operator=(const Point &other);
	~Point();

	//Param
	Point(const float x, const float y);

	//Getters
	Fixed getX() const;
	Fixed getY() const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
