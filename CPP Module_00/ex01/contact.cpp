/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:35:06 by gkamanur          #+#    #+#             */
/*   Updated: 2025/11/19 15:48:29 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"


void    Contact::set(Data data, const std::string &value)
{
    switch(data)
    {
        case FIRSTNAME:
            this->firstname = value;
            break ;
        case LASTNAME:
            this->lastname = value;
            break ;
        case NICKNAME:
            this->nickname = value;
            break ;
        case PHONE:
            this->phone = value;
            break ;
        case DARKEST_SECRET:
            this->darkest_secret = value;
            break;
        default:
            break ;
    }
};

std::string Contact::get(Data data) const
{
    switch (data)
    {
        case FIRSTNAME:
            return (this->firstname);
        case LASTNAME:
            return (this->lastname);
        case NICKNAME:
            return (this->nickname);
        case PHONE:
            return (this->phone);
        case DARKEST_SECRET:
            return (this->darkest_secret);
        default:
            return("");
              
    }    
};
