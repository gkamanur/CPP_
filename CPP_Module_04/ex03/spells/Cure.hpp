/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:50:39 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/25 10:55:32 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "../includes/Amateria.hpp"

class Cure : public Amateria
{
    public:
        Cure();
        Cure(const Cure &src);
        Cure &operator=(const Cure &rhs);
        virtual ~Cure();
        
        virtual Amateria* clone() const;
        virtual void use(ICharacter &target);
};

#endif