/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:43:16 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/25 14:18:07 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_HPP
# define FIRE_HPP
# include "../includes/Amateria.hpp"
# include "../includes/ICharacter.hpp"

class Fire : public Amateria
{
    public:
        Fire();
        Fire(const Fire &src);
        Fire &operator=(const Fire &rhs);
        virtual ~Fire();

        virtual Amateria* clone() const;
        virtual void use(ICharacter &target);
};
# endif