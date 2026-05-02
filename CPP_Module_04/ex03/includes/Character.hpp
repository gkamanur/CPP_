/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:44:26 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/26 13:49:09 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Amateria;
class Character : public ICharacter
{
    private:
        std::string _name;
        Amateria*   _inventory[4];
        Amateria*   _floor[100];
        int         _floorCount;
    public:
        Character();
        Character(std::string const &name);
        Character(const Character &src);
        Character &operator=(const Character &rhs);
        virtual ~Character();
        
        virtual std::string const &getName() const;
        virtual void equip(Amateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter &target);
        
};
#endif