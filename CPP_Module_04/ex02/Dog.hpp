/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:18:56 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 16:35:33 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal_.hpp"
# include "Brain.hpp"

class Dog : public Animal_
{
    private:
        Brain *_brain;
    public:
        Dog();
        Dog(const Dog &src);
        Dog &operator=(const Dog &rhs);
        virtual ~Dog();
        
        virtual void makesound() const;
        Brain*  getBrain() const;   
};
# endif