/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:04:20 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/27 17:23:52 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>

class BitcoinExchange
{
    private:
        std::map <std::string, float> _database;
        bool isValidDate(const std::string &date) const;
        std::string _trim(const std::string& s) const;
        bool _isvalidvalue(const std::string& value, float& out) const;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& rhs);
        ~BitcoinExchange();
       
        void loadDb(const std::string& file_name);
        void ProcessInfile(const std::string& file_name) const;;
        float getRate(const std::string& date) const;

        void printRates() const;
        
};
#endif