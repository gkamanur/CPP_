/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:11:58 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 19:45:17 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal_.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "Brain.hpp"

int main()
{
    Tracker::init();
    {
    Print::boldBlue("-----Polymorphism with Abstract base-------");
    const Animal_ *a = new Dog();
    const Animal_ *b = new Cat();

    Print::print(a->getType());
    Print::print(b->getType());
    a->makesound();
    b->makesound();
    delete a;
    delete b;
    
    Print::boldBlue("----Array of Animals_ -------");
    const int size = 10;
    const Animal_* animals[size];
    
    for (int k = 0; k < size; k++)
    {
        if (k < size / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }
    
    Print::boldBlue("-----Making Sounds------");
    for (int k = 0; k < size; k++)
    {
        Print::print(animals[k]->getType() + ":");
        animals[k]->makesound();
    }
    
    Print::boldBlue("-----Deleting array-------");
    for (int k = 0; k < size; k++)
    {
        delete animals[k];
    }
    Print::boldBlue("--------Deep copy test------");
    Dog org;
    org.getBrain()->ideas[0] = "Abstract Thoughts";
    
    Dog copy(org);
    copy.getBrain()->ideas[0] = "Concrete Thoughts";

    Print::print("Original idea[0]: " + org.getBrain()->ideas[0]);
    Print::print("Copy idea[0]    : " + copy.getBrain()->ideas[0]);

    Print::boldRed("Destruction");
    }
    Tracker::report();
    return(0);
}