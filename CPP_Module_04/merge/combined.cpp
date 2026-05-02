// ===== COMBINED HEADERS =====

// ===== ./files/Amateria.hpp =====


#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "../print/Print.hpp"
# include "ICharacter.hpp"

class Amateria
{
    protected:
        std::string _type;
    public:
        Amateria();
        Amateria(std::string const &type);
        Amateria(const Amateria &src);
        Amateria &operator=(const Amateria &rhs);
        virtual ~Amateria();
        
        std::string const &getType() const;
        virtual Amateria* clone() const = 0;
        virtual void use(ICharacter &target);
        
};
#endif

// ===== ./files/Character.hpp =====


#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "Amateria.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        Amateria*   _inventory[4];
        Amateria*   _floor[100];
        int         _floorCount;
    public:
        Character();
        Character(std::string const &name);
        Character(const Character &src);
        Character &operator=(const Character &rhs);
        virtual ~Character();
        
        virtual std::string const &getName() const = 0;
        virtual void equip(Amateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter &target);
        
};
#endif

// ===== ./files/Cure.hpp =====



#ifndef CURE_HPP
# define CURE_HPP

# include "Amateria.hpp"

class Cure : public Amateria
{
    public:
        Cure();
        Cure(const Cure &src);
        Cure &operator=(const Cure &rhs);
        virtual ~Cure();
        
        virtual Amateria* clone() const;
        virtual void use(ICharacter &target);
};

#endif

// ===== ./files/Ice.hpp =====



#ifndef ICE_HPP
# define ICE_HPP
# include "Amateria.hpp"

class Ice : public Amateria
{
    public:
        Ice();
        Ice(const Ice &src);
        Ice &operator=(const Ice &rhs);
        virtual ~Ice();
        
        virtual Amateria* clone() const;
        virtual void use (ICharacter &target);
};
# endif

// ===== ./files/ICharacter.hpp =====


#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
# include "../print/Print.hpp"

class Amateria;

class ICharacter
{
    public:
        virtual ~ICharacter();
        virtual std::string const &getName() const = 0;
        virtual void equip(Amateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter &target) = 0;
};

#endif

// ===== ./files/IMateriaSource.hpp =====



#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "Amateria.hpp"

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(Amateria*) = 0;
        virtual Amateria* createMateria(std::string const &type) = 0;
};

# endif

// ===== ./files/MateriaSource.hpp =====



#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
    private:
        Amateria* _templates[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &src);
        MateriaSource &operator=(const MateriaSource &rhs);
        virtual ~MateriaSource();
        
        virtual void learnMateria(Amateria* m);
        virtual Amateria* createMateria(std::string const &type);
};
#endif

// ===== ./files/Print.hpp =====



#ifndef PRINT_HPP
# define PRINT_HPP

#include <iostream>
#include <string>

class Print
{
public:
    // Reset
    static std::string reset() { return "\033[0m"; }

    // Regular colors
    static std::string red() { return "\033[31m"; }
    static std::string green() { return "\033[32m"; }
    static std::string yellow() { return "\033[33m"; }
    static std::string blue() { return "\033[34m"; }

    // Bold colors
    static std::string boldRed() { return "\033[1;31m"; }
    static std::string boldGreen() { return "\033[1;32m"; }
    static std::string boldYellow() { return "\033[1;33m"; }
    static std::string boldBlue() { return "\033[1;34m"; }

    // Italic colors
    static std::string italicRed() { return "\033[3;31m"; }
    static std::string italicGreen() { return "\033[3;32m"; }
    static std::string italicYellow() { return "\033[3;33m"; }
    static std::string italicBlue() { return "\033[3;34m"; }

    // --- PRINT FUNCTIONS ---

    static void red(const std::string &msg) {
        std::cout << red() << msg << reset() << std::endl;
    }

    static void boldRed(const std::string &msg) {
        std::cout << boldRed() << msg << reset() << std::endl;
    }

    static void italicRed(const std::string &msg) {
        std::cout << italicRed() << msg << reset() << std::endl;
    }

    static void green(const std::string &msg) {
        std::cout << green() << msg << reset() << std::endl;
    }

    static void boldGreen(const std::string &msg) {
        std::cout << boldGreen() << msg << reset() << std::endl;
    }

    static void italicGreen(const std::string &msg) {
        std::cout << italicGreen() << msg << reset() << std::endl;
    }

    static void yellow(const std::string &msg) {
        std::cout << yellow() << msg << reset() << std::endl;
    }

    static void boldYellow(const std::string &msg) {
        std::cout << boldYellow() << msg << reset() << std::endl;
    }

    static void italicYellow(const std::string &msg) {
        std::cout << italicYellow() << msg << reset() << std::endl;
    }

    static void blue(const std::string &msg) {
        std::cout << blue() << msg << reset() << std::endl;
    }
    
    static void boldBlue(const std::string &msg) {
    std::cout << boldBlue() << msg << reset() << std::endl;
    }

    static void italicBlue(const std::string &msg) {
    std::cout << italicBlue()  << msg << reset() << std::endl;
    }
    // Generic print
    static void print(const std::string &msg) {
        std::cout << msg << std::endl;
    }

};

# endif

// ===== COMBINED SOURCES =====

// ===== ./files/Amateria.cpp =====




Amateria::Amateria() : _type("default"){}
Amateria::Amateria(std::string const &type) : _type(type){}
Amateria::Amateria(const Amateria &src) : _type(src._type){}

Amateria &Amateria::operator=(const Amateria &rhs)
{
    (void)rhs;
    return *this;
}

Amateria::~Amateria(){}

std::string const &Amateria::getType() const
{
    return (_type);
}

void Amateria::use(ICharacter &target)
{
    (void)target;
}

// ===== ./files/Character.cpp =====



# include "Character.hpp"

Character::Character() : _name("unnamed"), _floorCount(0)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = 0;
    for (int i = 0; i < 100; i++)
        _floor[i] = 0;
}

Character::Character(std::string const &name) : _name(name), _floorCount(0)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = 0;
    for (int i = 0; i < 100; i++)
        _floor[i] = 0;
}

Character::Character(const Character &src) : _name(src._name), _floorCount(0)
{
    for (int i = 0; i < 4; i++)
    {
        if (src._inventory[i])
            _inventory[i] = src._inventory[i]->clone();
        else
            _inventory[i] = 0;
    }
    for (int i = 0; i < 100; i++)
        _floor[i] = 0;
}

Character &Character::operator=(const Character &rhs)
{
    if (this != &rhs)
    {
        _name = rhs._name;
        for(int i = 0; i < 4; i++)
        {
            delete _inventory[i];
            if (rhs._inventory[i])
                _inventory[i] = rhs._inventory[i]->clone();
            else
                _inventory[i] = 0;
            
        }
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete _inventory[i];
    for (int i = 0; i < _floorCount; i++)
        delete _floor[i];
}

std::string const &Character::getName() const
{
    return _name;
}

void Character::equip(Amateria *m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return ;
    if (_floorCount < 100)
    {
        _floor[_floorCount] = _inventory[idx];
        _floorCount++;
    }
    _inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return ;
    _inventory[idx]->use(target);
}

// ===== ./files/Cure.cpp =====



# include "Cure.hpp"

Cure::Cure() :Amateria("cure"){}

Cure::Cure(const Cure &src) : Amateria(src){}

Cure &Cure::operator=(const Cure &rhs)
{
    (void)rhs;
    return *this;
}

Cure::~Cure(){};

Amateria* Cure::clone() const{
    return (new Cure (*this));
}

void Cure::use(ICharacter &target)
{
    Print::print("* heals " + target.getName() + "'s wounds *");
}

// ===== ./files/Ice.cpp =====


# include "Ice.hpp"

Ice::Ice() : Amateria("ice"){}

Ice::Ice(const Ice &src) : Amateria(src){}

Ice &Ice::operator=(const Ice &rhs)
{
    (void) rhs;
    return *this;
}

Ice::~Ice(){}

Amateria* Ice::clone() const
{
    return(new Ice (*this));
}

void Ice::use(ICharacter &target)
{
    Print::print("* shoots an ice bolt at " + target.getName() + " *");
}

// ===== ./files/MateriaSource.cpp =====



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
