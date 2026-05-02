/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:36:21 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/11 14:34:20 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);
    
    Point p1(2.0f, 2.0f);
    std::cout << "Point (2, 2) inside triangle:" << (bsp(a, b, c, p1) ? "true" : "false") << bsp(a, b, c, p1) << std::endl;

    return (0);
}