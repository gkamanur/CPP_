/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:42:46 by gkamanur          #+#    #+#             */
/*   Updated: 2026/02/12 13:47:00 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string> 
#include <cctype> // toupper

class Megaphone
{
    private:
        std::string toupperCase(const std::string &str) const;
        std::string getdefaultmssg(void) const;
        void print(const std::string &message) const;
    public:
        void announce(int ac, char **av) const; 
};

std::string Megaphone:: toupperCase(const std::string &str)const
{
    std::string result;
    result.reserve(str.size()); //reallocates 

    for (size_t i = 0; i < str.size(); i++)
        result += static_cast<char>(std::toupper(static_cast<unsigned char> (str[i])));

    return result;
};

std::string Megaphone::getdefaultmssg(void)const
{
    return ("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
};

void Megaphone::print(const std::string &message) const
{
    std::cout << message << std::endl;
};

void Megaphone::announce (int ac, char **av) const
{
    if (ac == 1)
    {
        this->print(this->getdefaultmssg());
        return ;
    }
    std::string input;
    for (int i = 1; i < ac; i++)
    {
        input += this->toupperCase(av[i]);
        if (i < ac - 1)     // add space ONLY if not last argument
            input += ' ';
    }
    this->print(input);

};

int main (int ac, char **av)
{
    Megaphone megaphone;
    megaphone.announce(ac,av);
    return (0);
}
