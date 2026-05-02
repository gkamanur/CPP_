/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tracker.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 19:30:21 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 20:10:17 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tracker.hpp"

int Tracker::animalCtor = 0;
int Tracker::animalDtor = 0;
int Tracker::animalCopy = 0;

int Tracker::dogCtor = 0;
int Tracker::dogDtor = 0;
int Tracker::dogCopy = 0;

int Tracker::catCtor = 0;
int Tracker::catDtor = 0;
int Tracker::catCopy = 0;

int Tracker::brainCtor = 0;
int Tracker::brainDtor = 0;
int Tracker::brainCopy = 0;

void Tracker::init()
{
    animalCtor = animalDtor = animalCopy = 0;
    dogCtor = dogDtor = dogCopy = 0;
    catCtor = catDtor = catCopy = 0;
    brainCtor = brainDtor = brainCopy = 0;
}

void Tracker::report() 
{
    std::cout << "\n===== TRACKER REPORT =====\n";
    reportType("Animal", animalCtor, animalDtor, animalCopy);
    reportType("Dog", dogCtor, dogDtor, dogCopy);
    reportType("Cat", catCtor, catDtor, catCopy);
    reportType("Brain", brainCtor, brainDtor, brainCopy);
    std::cout << "===========================\n";
}

void Tracker::reportType(const char* name, int ctor, int dtor, int copy) {
    std::cout << name << ":\n";
    std::cout << "  Constructors : " << ctor << "\n";
    std::cout << "  Destructors  : " << dtor << "\n";
    std::cout << "  Copies       : " << copy << "\n";
    std::cout << std::endl;
}