/* ************************************************************************** */
/*                                                                            */
/*   Zombie.cpp - Implementation of the Zombie class                          */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << this->_name << " is born!" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << this->_name << " is destroyed!" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}



