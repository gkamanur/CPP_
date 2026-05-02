/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 10:54:07 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/01 12:28:35 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# include <cmath>

class ScalarConverter
{
    private: 
    // prevents instantiation
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter &rhs);
        ~ScalarConverter();
    //*
        static bool isChar(const std::string &data);
        static bool isInt(const std::string &data);
        static bool isFloat(const std::string &data);
        static bool isDouble(const std::string &data);
        static bool isPsuedo(const std::string &data);
        
        static void printChar(int value);
        static void printInt(int value);
        static void printFloat(float value);
        static void printDouble(double value);

        static void convertFromChar(const std::string &data);
        static void convertFromInt(const std::string &data);
        static void convertFromFloat(const std::string &data);
        static void convertFromDouble(const std::string &data);
        static void convertFromPseudo(const std::string &data);
    public:
        static void convert (const std::string &data);
        // void conv(const std::string &data);
};
# endif