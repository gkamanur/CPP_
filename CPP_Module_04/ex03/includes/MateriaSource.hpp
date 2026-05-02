/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:57:42 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/25 14:15:39 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class Amateria;
class MateriaSource : public IMateriaSource
{
    private:
        Amateria* _templates[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &src);
        MateriaSource &operator=(const MateriaSource &rhs);
        virtual ~MateriaSource();
        
        virtual void learnMateria(Amateria* m);
        virtual Amateria* createMateria(std::string const &type);
};
#endif