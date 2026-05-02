/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:18:52 by gkamanur          #+#    #+#             */
/*   Updated: 2025/11/19 17:07:08 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Contact
{
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phone;
        std::string darkest_secret;
    public:
        enum Data
        {
            FIRSTNAME,
            LASTNAME,
            NICKNAME,
            PHONE,
            DARKEST_SECRET
        };
        void    set(Data data, const std::string &value);
        std::string get(Data data) const;
};
