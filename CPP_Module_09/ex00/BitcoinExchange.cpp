/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:11:22 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/27 18:05:48 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <stdexcept>

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
    : _database(other._database){}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
    if (this != &rhs)
        _database = rhs._database;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

std::string BitcoinExchange::_trim(const std::string& s) const
{
    size_t start = s.find_first_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";
    size_t end = s.find_last_not_of(" \t\n\r");
    return (s.substr(start, end - start + 1));
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast <unsigned char>(date[i])))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    
    int dim[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    bool leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    if (leap)
        dim[1] = 29;
    if (day > dim[month -1])
        return false;

    return true;  
}

bool BitcoinExchange::_isvalidvalue(const std::string& value, float& out) const
{
    if(value.empty())
    {
        std::cout << "Error: Bad input ==> " << value << std::endl;
        return false;
    }
    char* endptr = 0;
    double v = std::strtod(value.c_str(), &endptr);
    if (endptr == value.c_str() || *endptr != '\0')
    {
        std::cout << "Error: bad input ==> " << value << std::endl;
        return false;
    }
    if (v < 0)
    {
        std::cout << "Error: not a positive number " << std::endl;
        return false;
    }
    if (v > 1000)
    {
        std::cout << "Error: too large numebr " << std::endl;
        return false;
    }
    out = static_cast <float> (v);
    return true;
}

void BitcoinExchange::loadDb(const std::string& file_name)
{
    std::ifstream file(file_name.c_str());
    if(!file.is_open())
        throw std::runtime_error("Could not open the Database file: " );
    
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        size_t comma = line.find(',');
        if(comma == std::string::npos)
            continue;
        std::string date = _trim(line.substr(0, comma));
        std::string price = _trim(line.substr(comma + 1));
        if(date.empty() || price.empty())
            continue;
        _database[date] = static_cast<float>(std::atof(price.c_str()));
    }
    file.close();
    if(_database.empty())
        throw std::runtime_error("Error: database is empty...");    
}

float BitcoinExchange::getRate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
    if (it == _database.end() || it->first != date)
    {
        if (it == _database.begin())
            throw std::runtime_error("Error: date is earlier than the DB");
        --it;
    }
    return(it->second);
}

void BitcoinExchange::ProcessInfile(const std::string& filename) const
{
    std::ifstream file (filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: could not open the input..." << std::endl;
        return ;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        size_t pipe = line.find('|');
        if (pipe == std::string::npos)
        {
            std::cout << "Error: bad input with INFILE ==> " << line << std::endl;
            continue ;
        }

        std::string date = _trim(line.substr(0, pipe));
        std::string vstr = _trim(line.substr(pipe + 1));
        
        if (!isValidDate(date))
        {
            std::cout << "Error: bad input ==> " << date << std::endl;
            continue ;
        }
        float value;
        if(!_isvalidvalue(vstr, value))
            continue ;
        
        try
        {
            float rate = getRate(date);
            std::cout << date << " ==> " << value << " = "
                << (value * rate) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    file.close();
    
}