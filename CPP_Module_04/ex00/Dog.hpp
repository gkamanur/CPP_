/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:18:56 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 11:20:03 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal{
    public:
        Dog();
        Dog(const Dog &src);
        Dog &operator=(const Dog &rhs);
        virtual ~Dog();
        
        virtual void makesound() const;      
};
# endif