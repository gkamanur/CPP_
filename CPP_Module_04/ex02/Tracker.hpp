/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tracker.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 19:17:02 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 19:38:23 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../print/Print.hpp"

class Tracker {
public:
    // Animal
    static int animalCtor;
    static int animalDtor;
    static int animalCopy;

    // Dog
    static int dogCtor;
    static int dogDtor;
    static int dogCopy;

    // Cat
    static int catCtor;
    static int catDtor;
    static int catCopy;

    // Brain
    static int brainCtor;
    static int brainDtor;
    static int brainCopy;

    // ===== INIT FUNCTION =====

    static void init();
    // ===== REPORT =====
    static void report();


private:
    static void    reportType(const char* name, int ctor, int dtor, int copy);
};