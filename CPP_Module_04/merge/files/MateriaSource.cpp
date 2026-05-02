/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:04:28 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/24 16:17:27 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _templates[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    for (int i = 0; i < 4; i++)
    {
        if (src._templates[i])
            _templates[i] = src._templates[i]->clone();
        else
            _templates[i] = 0;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            delete _templates[i];
            if (rhs._templates[i])
                _templates[i] = rhs._templates[i]->clone();
            else
                _templates[i] = 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete _templates[i];
}

void MateriaSource::learnMateria(Amateria* m)
{
    if (!m)
     return ;
    for (int i = 0; i < 4; i++)
    {
        if (!_templates[i])
        {
            _templates[i] = m;
            return ;
        }
    }
    delete m;
}

Amateria* MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_templates[i] && _templates[i]->getType() == type)
            return _templates[i]->clone();
    }
    return 0;
}