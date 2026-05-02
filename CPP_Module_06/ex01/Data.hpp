/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:24:05 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/07 15:38:04 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>
#include <stdint.h>

struct Data
{
    int id;
    std::string name;
    double value;
    
    Data() : id(0), name(""), value(0.0){}
    Data(int i, const std::string &n, double v) : id(i), name(n), value(v){}
};

#endif