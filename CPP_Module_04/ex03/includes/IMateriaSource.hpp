/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:32:15 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/31 12:10:43 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include <string>

class Amateria;

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {};
        virtual void learnMateria(Amateria*) = 0;
        virtual Amateria* createMateria(std::string const &type) = 0;
};

# endif

