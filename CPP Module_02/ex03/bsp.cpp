/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:18:58 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/11 14:17:34 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed crossprod(Point const &p1, Point const &p2, Point const &p3)
{
    return(((p1.getX() - p3.getX()) * (p2.getY() - p3.getY())) 
          - ((p2.getX() - p3.getX()) * (p1.getY() - p3.getY())));
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
    Fixed d1 = crossprod(p, a, b);
    Fixed d2 = crossprod(p, b, c);
    Fixed d3 = crossprod(p, c, a);
    
    bool has_neg = (d1.getRawBits() < 0) || (d2.getRawBits() < 0) || (d3.getRawBits() < 0);
    bool has_pos = (d1.getRawBits() > 0) || (d2.getRawBits() > 0) || (d3.getRawBits() > 0);

    if((d1.getRawBits() == 0) || (d2.getRawBits() == 0) || (d3.getRawBits() == 0))
        return (false);
// mixed signs the point is outside
// same sign the point is inside
    return (!(has_neg && has_pos));
}
