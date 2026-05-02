/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:11:58 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 20:26:50 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int main()
{
    Print::boldBlue("------------Subject Tests");
    const Animal *one = new Animal();
    const Animal *two = new Dog();
    const Animal *three = new Cat();
    
    Print::yellow(two->getType());
    Print::yellow(three->getType());
    two->makesound();
    three->makesound();
    one->makesound();
    
    delete one;
    delete two;
    delete three;
    
    Print::boldBlue("------------WrongAnimal tests-------");
    const WrongAnimal *a = new WrongAnimal();
    const WrongAnimal *b = new WrongCat();
    
    Print::print(b->getType() + " ");
    b->makesound();
    a->makesound();
    
    delete a;
    delete b;
    
    Print::boldBlue("------------Stack Allocation tests--");
    Dog dog;
    Cat cat;
    Print::green("Dog type: ");
    Print::yellow(dog.getType());
    Print::green("Cat type: ");
    Print::yellow(cat.getType());
    dog.makesound();
    cat.makesound();
    
    Print::boldBlue("------------Copy Tests");
    Dog dogcopy(dog);
    Cat catcopy(cat);
    Print::green("Dogcopy type: ");
    Print::yellow(dog.getType());
    Print::green("Catcopy type: ");
    Print::yellow(cat.getType());
    dog.makesound();
    cat.makesound();
    
    Print::boldBlue("*********Destruction**********");
    return(0);
}