/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:46:35 by gkamanur          #+#    #+#             */
/*   Updated: 2025/11/19 18:01:53 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "contact.hpp"

class Phonebook
{

  private:
    Contact contacts[8];
    int count;
    int index;
    
    std::string truncateString(const std::string &str) const;
    void        displayrow(int index) const;

    //helper functions
    static const int NUM_FIELDS = 5;
    static Contact::Data getfieldbyindex(int index);
    static const char* getpromptbyindex(int index);
    static const char* getfieldnamebyindex(int index);

    //validation
    static bool isdigitsonly(const std::string &str);
    bool isvalidinput(Contact::Data data, const std::string &input) const;
    
    
  public:
    Phonebook();
    void    addcontact();
    void    validate_addcontact();
    void    searchcontact() const;  
};