/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:11:58 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 15:50:17 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "Brain.hpp"

int main()
{
    Print::boldBlue("------------Subject Tests");
    const Animal *two = new Dog();
    const Animal *three = new Cat();

    delete two;
    delete three;
    
    Print::boldBlue("------------Array of Animals");
    const int size = 10;
    const Animal* animals[size];
    for(int k = 0; k < size; k++)
    {
        if (k < size / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }
    
    Print::boldBlue(" Making Sounds");
    for (int k = 0; k < size; k++)
    {
        Print::print(animals[k]->getType());
        animals[k]->makesound();
    }
    
    Print::boldBlue("----Deleting Arrays-----");
    for (int k = 0; k < size; k++)
        delete animals[k];
    
    Print::boldBlue("Deep copy Test");
    Dog org;
    org.getBrain()->ideas[0] = "chase the ball";
    org.getBrain()->ideas[1] = "Eat treats";

    Dog copy(org);
    Print::yellow("Original Brain idea[0]: ");
    Print::print(org.getBrain()->ideas[0]);
    Print::yellow("Copy Brain idea[0]: ");
    Print::print(copy.getBrain()->ideas[0]);
    
    copy.getBrain()->ideas[0] = "Sleep all day";
    Print::green("After modifying copy : ");
    Print::yellow("Original Brain idea[0]: ");
    Print::print(org.getBrain()->ideas[0]);
    Print::yellow("Copy Brain idea[0]: ");
    Print::print(copy.getBrain()->ideas[0]);
    
    Print::boldBlue("-------Deep Copy assignment test------");
    Dog ass;
    ass = org;
    Print::yellow("Assigned Brain idea[0]: ");
    Print::print(ass.getBrain()->ideas[0]);
    Print::yellow("Assigned Brain idea[1]: ");
    Print::print(ass.getBrain()->ideas[1]);
    ass.getBrain()->ideas[0] = "Dig a hole";
    Print::yellow("Original Brain idea[0]: ");
    Print::print(org.getBrain()->ideas[0]);
    Print::yellow("Assigned Brain idea[0]: ");
    Print::print(ass.getBrain()->ideas[0]);
    
    Print::boldBlue("*********Destruction**********");
    return(0);
}