/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:10:29 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 16:35:21 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal_.hpp"
# include "Brain.hpp"
class Cat : public Animal_
{
    private:
        Brain *_brain;
    public:
        Cat();
        Cat(const Cat &src);
        Cat &operator=(const Cat &rhs);
        virtual ~Cat();
        
        virtual void makesound() const;
        Brain*       getBrain() const; 
};
# endif
