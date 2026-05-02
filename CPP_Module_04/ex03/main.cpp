/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Amateria.hpp"
#include "spells/Ice.hpp"
#include "spells/Cure.hpp"
#include "includes/ICharacter.hpp"
#include "includes/Character.hpp"
#include "includes/IMateriaSource.hpp"
#include "includes/MateriaSource.hpp"

int main()
{
	Print::boldBlue("------Subject tests------");
	IMateriaSource* source = new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());

	ICharacter* me = new Character("Alpha");
	Amateria* tmp;
	tmp = source->createMateria("ice");
	me->equip(tmp);
	tmp = source->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("Beta");
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete source;

	Print::boldBlue("------Extended Tests------");
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* hero = new Character("hero");

	Amateria* m1 = src->createMateria("ice");
	Amateria* m2 = src->createMateria("cure");
	Amateria* m3 = src->createMateria("ice");
	Amateria* m4 = src->createMateria("cure");

	hero->equip(m1);
	hero->equip(m2);
	hero->equip(m3);
	hero->equip(m4);

	ICharacter* villain = new Character("villain");
	Print::yellow("===using all 4 slots===");
	hero->use(0, *villain);
	hero->use(1, *villain);
	hero->use(2, *villain);
	hero->use(3, *villain);

	Print::yellow("===Unequip Test===");
	hero->unequip(0);
	hero->use(0, *villain);

	Print::yellow ("====Full inventory Test====");
	Amateria* extra = src->createMateria("ice");
	hero->equip(extra);
	hero->use(0, *villain);

	Print::boldBlue("Unknown Materia test");
	Amateria* unknown = src->createMateria("fire");
	if (!unknown)
		Print::print("Unknown Materia type is Null");
	
	Print::boldBlue("Deep copy test");
	Character original("original");
	Amateria *iceM = src->createMateria("ice");
	original.equip(iceM);
	original.use(0, *villain);

	Character copied(original);
	copied.use(0, *villain);

	Print::boldBlue("==Invalid index tests==");
	hero->use(-1, *villain);
	hero->use(4, *villain);
	hero->unequip(-1);
	hero->unequip(4);

	delete villain;
	delete hero;
	delete src;

	Print::boldRed("All done");
	return (0);

}
