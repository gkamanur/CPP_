/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:54:28 by gkamanur          #+#    #+#             */
/*   Updated: 2026/02/12 16:28:50 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "phonebook.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

Phonebook:: Phonebook() : count(0), index(0){  
}

bool Phonebook::isdigitsonly(const std::string &str)
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); i++)
    {
        char c = str[i];

        if (!std::isdigit(static_cast<unsigned char>(c)) &&
            c != '+' &&
            c != ' ')
        {
            return false;
        }
    }
    return true;
}

bool Phonebook::isvalidinput(Contact::Data data, const std::string &input) const
{
    if (input.empty())
    {
        Utils::printError("Field cannot be empty !!!");
        return (false);
    }
    if (data == Contact::PHONE)
    {
        if (!isdigitsonly(input))
        {
            Utils::printError("only digits are allowed here !!!!");
            return (false);
        }
    }
    return (true);
}

Contact::Data Phonebook::getfieldbyindex(int index)
{
    static Contact::Data fields[] = {
        Contact::FIRSTNAME,
        Contact::LASTNAME,
        Contact::NICKNAME,
        Contact::PHONE,
        Contact::DARKEST_SECRET
    };
    
    return (fields[index]);
}

const char* Phonebook::getpromptbyindex(int index)
{
    static const char *prompt[] = {
        "Enter Firstname      > ",
        "Enter Lastname       > ",
        "Enter Nickname       > ",
        "Enter Phone          > ",
        "Enter Darkest_secret > "
    };
    
    return (prompt[index]);
}

const char* Phonebook::getfieldnamebyindex(int index)
{
    static const char* fieldname[] = {
        "First Name     : ",
        "Last Name      : ",
        "Nick Name      : ",
        "Phone Number   : ",
        "Darkest Secret : "
    };
    
    return(fieldname[index]);
}

std::string Phonebook::truncateString(const std::string &str) const
{
    //let pass this 123456789abc it is saved as 12345678. so that it tells it has an extension
    if (str.length() > 10)
        return(str.substr(0, 9) + "."); 
    return (str);
}

void    Phonebook::displayrow(int index) const
{
    std::stringstream ss;
    ss << index;
    std::string indexStr = ss.str();
    std::string cols[4] = {
        indexStr,
        truncateString(contacts[index].get(Contact::FIRSTNAME)),
        truncateString(contacts[index].get(Contact::LASTNAME)),
        truncateString(contacts[index].get(Contact::NICKNAME))
    };
    //print data row while on Search
    for (int i = 0; i < 4; i++)
    {
        std::cout << std::setw(10);
        Utils::print(cols[i]);
        Utils::print("|");
    }
}

void    Phonebook::addcontact()
{
    Contact     new_contact;
    std::string input;


    for (int i = 0; i < 5; i++)
    {
        Utils::print(getpromptbyindex(i));
        std::getline(std::cin, input);
        if (std::cin.eof() || input.empty())
        {
            Utils::printError("Invalid input : you entry is not saved $");
            return ;
        }
        new_contact.set(getfieldbyindex(i), input);
    }
    if (count < 8)
    {
        contacts[count] = new_contact;
        count++;
    }
    else
    {
        contacts[index] = new_contact;
        index = (index + 1) % 8;
    }
    std::cout << "...................................................................." << std::endl << std::endl;
    Utils::println("Contact Added Seccessfully!!!!");
}

void    Phonebook::validate_addcontact()
{
    Contact new_contact;
    std::string input;
    
    for (int i = 0 ; i < NUM_FIELDS; i++)
    {
        Contact::Data curr = getfieldbyindex(i);
        while (1)
        {
            Utils::print(getpromptbyindex(i));
            std::getline(std::cin, input);
            
            if (std::cin.eof())
            {
                Utils::println("\nContact not saved");
                return ;
            }
            if (isvalidinput(curr,input))
            {
                new_contact.set(curr, input);
                break ;
            }
            
        }
        
    }
    if (count < 8)
    {
        contacts[count] = new_contact;
        count++;
    }
    else
    {
        contacts[index] = new_contact;
        index = (index + 1) % 8;
    }
    std::cout << "--------------------------------------------------------------------" << std::endl << std::endl;
    Utils::println("Contact Added Seccessfully!!!!");

}

void    Phonebook::searchcontact() const
{
    std::string         input;
    int                 index;
    
    if (count == 0)
    {
        Utils::println("Phonbook is Empty");
        return ;
    }
    Utils::println("++++++++++++++++++++++++++++++++++++++++++++");
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First-Name" << "|";
    std::cout << std::setw(10) << "Last-Name" << "|";
    std::cout << std::setw(10) << "Nick-Name" << "|" << std::endl;
    Utils::println("+------------------------------------------+");
    
    for (int i = 0; i < count; i++)
    {
        displayrow(i);
        std::cout << std::endl;
    }
    Utils::println("++++++++++++++++++++++++++++++++++++++++++++");
    Utils::println("Enter INDEX to display > ");
    
    std::getline(std::cin, input);
    if (std::cin.eof())
        return ;
    
    std::stringstream   ss(input);
    
    if (!(ss >> index) || !(ss.eof()))
    {
        Utils::println("Inavlid Index");
        return ;
    }
    
    if (index < 0 || index >= count)
    {
        Utils::println("Index OutofRange !!!");
        return ;
    }
    
    //
    std::cout << "____________________________________________________________________" << std::endl << std::endl;
    for (int i = 0; i < NUM_FIELDS; i++)
    {
        Utils::print(getfieldnamebyindex(i));
        Utils::println(contacts[index].get(getfieldbyindex(i)));
    }
    std::cout << "-*-*-*-*-*-*-*--*-*-*-*-*-*-*--*-*-*-*-*-*-*--*-*-*-*-*-*-*--*-*-*-*-" << std::endl << std::endl;
}
