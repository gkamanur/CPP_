/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:31:05 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 13:33:30 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include "Animal.hpp"

class Brain
{
    public:
        std::string ideas[100];
        
        Brain();
        Brain(const Brain &src);
        Brain &operator=(const Brain &rhs);
        ~Brain();
};
#endif