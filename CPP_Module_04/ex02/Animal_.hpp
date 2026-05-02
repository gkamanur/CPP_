/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal_.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 09:46:59 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 16:31:03 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL__HPP
# define ANIMAL__HPP
# include "../print/Print.hpp"
# include "Tracker.hpp"

class Animal_
{
    protected:
        std::string _type;
    public:
        Animal_();
        Animal_(const Animal_ &src);
        Animal_ &operator=(const Animal_ &rhs);
        virtual ~Animal_();
        
        virtual void makesound() const = 0;
        std::string getType() const;       
};
# endif