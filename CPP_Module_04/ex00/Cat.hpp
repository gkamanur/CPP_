/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:10:29 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 11:13:04 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal{
    public:
        Cat();
        Cat(const Cat &src);
        Cat &operator=(const Cat &rhs);
        virtual ~Cat();
        
        virtual void makesound() const;      
};
# endif
