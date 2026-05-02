/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:05:15 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/13 18:21:38 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) 
{
    return (*this);
}
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string &data)
{
    if (data.length() == 1 && !std::isdigit(data[0]))
        return true;
    return false;
}

bool ScalarConverter::isInt(const std::string &data)
{
    if (data.empty())
        return false;
    
    size_t i = 0;
    if (data[0] == '-' || data[0] == '+')
        i = 1;
    if (i >= data.length())
        return false;
    for (; i < data.length(); i++)
    {
        if (!std::isdigit(data[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string &data)
{
    //float : 42.0f, -4.2f, 0,0f
    if (data.empty())
        return false;
        
    if (data[data.length() - 1] != 'f')
        return false;
    
    bool hasDec = false;
    bool hasDigit = false;
    size_t i = 0;
    
    if (data[0] == '-' || data[0] == '+')
        i = 1;
    for (; i < data.length() - 1; i++)
    {
        if (data[i] == '.')
            hasDec = true;
        else if (std::isdigit(data[i]))
            hasDigit = true;
        else if (data[i] != '-' && data[i] != '+')
            return false;
    }
    return (hasDec && hasDigit);
}
bool ScalarConverter::isDouble(const std::string &data)
{
    // Double looks like: 42.0, -4.2, 0.0
    if (data.empty())
        return false;
    
    // Check for pseudo-data
    if (data == "nan" || data == "+inf" || data == "-inf" || data == "inf")
        return false;
    
    // Must have a decimal point
    bool hasDecimal = false;
    bool hasDigit = false;
    size_t i = 0;
    
    if (data[0] == '-' || data[0] == '+')
        i = 1;
    
    for (; i < data.length(); i++)
    {
        if (data[i] == '.')
            hasDecimal = true;
        else if (std::isdigit(data[i]))
            hasDigit = true;
        else
            return false;
    }
    
    return hasDecimal && hasDigit;
}

bool ScalarConverter::isPsuedo(const std::string &data)
{
    return (data == "nan" || data == "nanf" || data == "inf"    \
        || data == "+inf" || data == "-inf" || data == "inff"   \
        || data == "+inff" || data == "-inff");
}

void ScalarConverter::printChar(int value)
{
    std::cout << "char :";
    if (value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (value < 32 || value == 127)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast <char> (value) << "'" << std::endl;
}

void ScalarConverter::printInt(int value)
{
    std::cout << "Int: " << value <<std::endl;
}

void ScalarConverter::printFloat(float value)
{
    float fract = value - static_cast<int>(value);
    if (fract < 0.0001f && fract > -0.0001f)
        std::cout << "Float: " << static_cast<int>(value) << "0.0f" << std::endl;
    else
        std::cout << "Float: " << value << std::endl;
}
void ScalarConverter::printDouble(double value)
{
    double fract = value - static_cast<int> (value);

    if (fract < 0.0001 && fract > -0.0001)
        std::cout << "Double: " << static_cast<int>(value) << ".0" << std::endl;
    else
        std::cout << "Double: " << value << std::endl;
}

void ScalarConverter::convertFromChar(const std::string &data)
{
    char c   = data[1]; //extract the bytes between the quotes
    int i    = static_cast<int> (c);
    float f  = static_cast<float> (c);
    double d = static_cast<double> (c);
    
    printChar(i);
    printInt(i);
    printFloat(f);
    printDouble(d); 
}

void ScalarConverter::convertFromInt(const std::string &data)
{
    long num = strtol(data.c_str(), NULL, 10);

    if ((num > std::numeric_limits<int>::max()) || 
        (num < std::numeric_limits<int>::min()))
    {
        std::cout << "Char: Impossible" << std::endl;
        std::cout << "Int : Impossible" << std::endl;
        std::cout << "Float : Impossible" << std::endl;
        std::cout << "Double: Impossible" << std::endl;
        return ;
    } 
    int i    = static_cast<int> (num);
    // char c   = static_cast<char> (i);
    float f  = static_cast<float> (i);
    double d = static_cast<double> (i);
    
    printChar(i);
    printInt(i);
    printDouble(d);
    printFloat(f);
    
}

void ScalarConverter::convertFromFloat(const std::string &data)
{
    float f  = strtof(data.c_str(), NULL);
    // char c   = static_cast<char>(static_cast<int>(f));
    int i    = static_cast<int>(f);
    double d = static_cast<double>(f);
    
    printChar(i);
    printInt(i);
    printFloat(f);
    printDouble(d);
}

void ScalarConverter::convertFromDouble(const std::string &data)
{
    double d = strtod(data.c_str(), NULL);
    // char c   = static_cast<char>(static_cast<int>(d));
    int i    = static_cast<int>(d);
    float f  = static_cast<float>(d);

    printChar(i);
    printInt(i);
    printFloat(f);
    printDouble(d);
}

void ScalarConverter::convertFromPseudo(const std::string &data)
{
    std::cout << "Char : Impossible" << std::endl;
    std::cout << "Int  : Impossible" << std::endl;
    if (data == "nan" || data == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (data == "inf" || data == "+inf" || data == "inff" || data == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (data == "-inf" || data == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::convert(const std::string &data)
{
    if (data.empty())
    {
            std::cout << "ERROR : Empty Data" << std::endl;
            return ;
    }
    
    if (isChar(data))
        convertFromChar(data);
    else if (isInt(data))
        convertFromInt(data);
    else if (isFloat(data))
        convertFromFloat(data);
    else if (isDouble(data))
        convertFromDouble(data);
    else if (isPsuedo(data))
        convertFromPseudo(data);
    else
        std::cout << "Error: Unknown data type" << std::endl;
}
