/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:25:00 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/24 16:28:09 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "Amateria.hpp"

class Ice : public Amateria
{
    public:
        Ice();
        Ice(const Ice &src);
        Ice &operator=(const Ice &rhs);
        virtual ~Ice();
        
        virtual Amateria* clone() const;
        virtual void use (ICharacter &target);
};
# endif