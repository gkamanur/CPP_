/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 09:27:02 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/25 14:11:52 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "../../print/Print.hpp"

class ICharacter;
class Amateria
{
    protected:
        std::string _type;
    public:
        Amateria();
        Amateria(std::string const &type);
        Amateria(const Amateria &src);
        Amateria &operator=(const Amateria &rhs);
        virtual ~Amateria();
        
        std::string const &getType() const;
        virtual Amateria* clone() const = 0;
        virtual void use(ICharacter &target);
        
};
#endif