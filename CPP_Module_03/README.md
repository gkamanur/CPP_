# C++ Module 03 — Complete Concept Guide

---

## 1. CLASS BASICS — What is a Class?

A class is a **blueprint** for creating objects. It bundles **data** (attributes) and **functions** (methods) together.

```cpp
class ClapTrap
{
    private:          // ← Access specifier
        std::string _name;       // ← Attribute (data)
        unsigned int _hitPoints;

    public:           // ← Access specifier
        void attack(const std::string &target);  // ← Method (behavior)
};
```

Think of it like a form:

```
┌──────────────────────────────┐
│         CLASS: ClapTrap      │
├──────────────────────────────┤
│  DATA (attributes):          │
│    _name         = "Alpha"   │
│    _hitPoints    = 10        │
│    _energyPoints = 10        │
│    _attackDamage = 0         │
├──────────────────────────────┤
│  BEHAVIOR (methods):         │
│    attack()                  │
│    takeDamage()              │
│    beRepaired()              │
└──────────────────────────────┘
```

When you write `ClapTrap a("Alpha");`, you create an **object** (instance) from this blueprint. Each object has its own copy of the data.

```
Object a:                    Object b:
┌────────────────┐           ┌────────────────┐
│ _name = "Alpha"│           │ _name = "Bravo"│
│ _hitPoints = 10│           │ _hitPoints = 10│
│ _energy    = 10│           │ _energy    = 10│
│ _damage    = 0 │           │ _damage    = 0 │
└────────────────┘           └────────────────┘
    Separate memory!             Separate memory!
```

---

## 2. ACCESS SPECIFIERS — `private`, `protected`, `public`

These control **who can access** your class members:

```
┌─────────────────────────────────────────────────────────┐
│                    ACCESS LEVELS                        │
├──────────┬──────────┬────────────────┬──────────────────┤
│ Keyword  │ Class    │ Derived Class  │ Outside World    │
│          │ itself   │ (child)        │ (main, etc.)     │
├──────────┼──────────┼────────────────┼──────────────────┤
│ private  │   ✅     │      ❌        │      ❌          │
│ protected│   ✅     │      ✅        │      ❌          │
│ public   │   ✅     │      ✅        │      ✅          │
└──────────┴──────────┴────────────────┴──────────────────┘
```

### Example:

```cpp
class ClapTrap
{
    private:
        std::string _name;      // Only ClapTrap methods can use this

    protected:
        unsigned int _hitPoints; // ClapTrap + ScavTrap/FragTrap can use this

    public:
        void attack();          // Anyone can call this
};
```

```cpp
// In ScavTrap (child of ClapTrap):
void ScavTrap::someFunction()
{
    _name;       // ❌ ERROR! private in ClapTrap
    _hitPoints;  // ✅ OK! protected — accessible from derived class
    attack();    // ✅ OK! public
}

// In main() (outside world):
int main()
{
    ClapTrap a("X");
    a._name;       // ❌ ERROR! private
    a._hitPoints;  // ❌ ERROR! protected
    a.attack();    // ✅ OK! public
}
```

### Why we changed `private` to `protected` in ex01:

In ex00, attributes are `private` because no one inherits from ClapTrap. But in ex01+, ScavTrap needs to write `_hitPoints = 100;` — it can't do that if `_hitPoints` is `private`. So we change to `protected`.

```
ex00:  private   → Only ClapTrap can touch its own data ✅
ex01+: protected → ScavTrap/FragTrap can also set values ✅
```

---

## 3. ORTHODOX CANONICAL FORM (OCF)

The 42 rule says every class MUST have these 4 functions. Here's **what each one does** and **when it's called**:

```
┌──────────────────────────────────────────────────────────────────┐
│              ORTHODOX CANONICAL FORM — THE 4 FUNCTIONS           │
├───────────────────────┬──────────────────────────────────────────┤
│ 1. Default Constructor│  ClapTrap a;           // called here   │
│ 2. Copy Constructor   │  ClapTrap b(a);        // called here   │
│ 3. Copy Assignment Op │  b = a;                // called here   │
│ 4. Destructor         │  } // end of scope     // called here   │
└───────────────────────┴──────────────────────────────────────────┘
```

### 3a. Default Constructor

```cpp
ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}
```

Called when you create an object **without arguments**: `ClapTrap a;`

### 3b. Parameterized Constructor (bonus — not OCF, but needed)

```cpp
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10) ...
```

Called when you create with arguments: `ClapTrap a("Alpha");`

### 3c. Copy Constructor

```cpp
ClapTrap::ClapTrap(const ClapTrap &src)
{
    *this = src;  // calls operator=
}
```

Called when you create a **new** object as a **copy**: `ClapTrap b(a);` or `ClapTrap b = a;`

**Why `const ClapTrap &src`?**
- `const` — We promise not to modify the source object
- `&` (reference) — **Critically important!** If we passed by value (`ClapTrap src`), the compiler would need to COPY `src` to pass it in → calls the copy constructor → which tries to copy → **infinite recursion!**

```
WITHOUT reference (BAD):
ClapTrap b(a)  →  copy a to make src  →  copy a to make src  →  ...forever

WITH reference (GOOD):
ClapTrap b(a)  →  src IS a (no copy needed)  →  copy members  →  done ✅
```

### 3d. Copy Assignment Operator

```cpp
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
    if (this != &rhs)         // self-assignment check
    {
        _name = rhs._name;
        _hitPoints = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    return *this;             // return reference to current object
}
```

Called when you assign one **existing** object to another: `b = a;`

**Why `if (this != &rhs)`?** Self-assignment protection:
```cpp
a = a;  // Without the check, this could be dangerous with dynamic memory
// this == &rhs  → true → skip assignment → safe!
```

**Why `return *this;`?** To allow chaining: `a = b = c;`

```
Copy Constructor vs Copy Assignment:
┌──────────────────────┬───────────────────────┐
│  ClapTrap b(a);      │  b already exists;    │
│  or ClapTrap b = a;  │  b = a;               │
│                      │                       │
│  Creating NEW object │  Assigning to EXISTING│
│  Copy Constructor ✅ │  Assignment Op ✅     │
└──────────────────────┴───────────────────────┘
```

### 3e. Destructor

```cpp
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}
```

Called **automatically** when the object goes out of scope (end of `}`). You never call it manually.

---

## 4. INITIALIZER LIST

```cpp
// METHOD 1: Initializer List (CORRECT WAY) ✅
ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
//  ^ colon starts the initializer list
{
}

// METHOD 2: Assignment in body (LESS EFFICIENT) ⚠️
ClapTrap::ClapTrap(const std::string &name)
{
    _name = name;         // First default-constructed "", then assigned "name"
    _hitPoints = 10;
}
```

```
Initializer List:                     Body Assignment:
┌────────────────┐                    ┌────────────────┐
│ Step 1: Create │                    │ Step 1: Create │
│ _name = "Alpha"│ ← directly        │ _name = ""     │ ← default
│ (1 step)       │                    │ Step 2: Assign │
└────────────────┘                    │ _name = "Alpha"│
                                      │ (2 steps)      │
                                      └────────────────┘
```

For `std::string` and other complex types, the initializer list avoids a useless default construction. **Always prefer initializer lists.**

---

## 5. INHERITANCE — The Core of Module 03

Inheritance lets you create a new class **based on** an existing one. The new class gets all the members of the old class.

```
              ┌──────────────┐
              │   ClapTrap   │  ← BASE class (parent)
              │  _name       │
              │  _hitPoints  │
              │  _energyPoints│
              │  _attackDamage│
              │  attack()    │
              │  takeDamage()│
              │  beRepaired()│
              └──────┬───────┘
                     │ inherits
          ┌──────────┴──────────┐
          │                     │
   ┌──────┴───────┐     ┌──────┴───────┐
   │   ScavTrap   │     │   FragTrap   │
   │              │     │              │
   │ HP=100       │     │ HP=100       │
   │ EP=50        │     │ EP=100       │
   │ AD=20        │     │ AD=30        │
   │ attack()  ✎  │     │              │
   │ guardGate()  │     │ highFivesGuys│
   └──────────────┘     └──────────────┘
     ✎ = overrides ClapTrap::attack()
```

### Syntax:

```cpp
class ScavTrap : public ClapTrap
//             ^^^^^^^^^^^^^^^^^
//    "ScavTrap publicly inherits from ClapTrap"
//    "ScavTrap IS-A ClapTrap"
```

### What does `public` inheritance mean?

```
┌─────────────────────────────────────────────────────┐
│  Inheritance Type:  class B : <TYPE> A              │
├──────────────┬──────────────────────────────────────┤
│ public       │ public→public, protected→protected   │
│ protected    │ public→protected, protected→protected│
│ private      │ public→private, protected→private    │
└──────────────┴──────────────────────────────────────┘
```

`public` inheritance preserves the access levels. This is the **standard** way — it models an "is-a" relationship.

### What ScavTrap inherits:

```cpp
ScavTrap b("Bravo");

// All these work because ScavTrap inherited them from ClapTrap:
b.attack("target");      // ← ScavTrap's OWN version (hides ClapTrap's)
b.takeDamage(10);        // ← Inherited from ClapTrap
b.beRepaired(5);         // ← Inherited from ClapTrap
b.guardGate();           // ← ScavTrap's OWN new method
```

---

## 6. CONSTRUCTION/DESTRUCTION CHAINING

This is **the most important concept** to understand about inheritance.

### Construction: BASE FIRST, then DERIVED

```
ScavTrap b("Bravo");

╔══════════════════════════════════════════╗
║ CONSTRUCTION ORDER (bottom-up building)  ║
║                                          ║
║  Step 1: Build ClapTrap part first       ║
║    ┌────────────────────┐                ║
║    │ ClapTrap("Bravo")  │ ← constructor  ║
║    │ _name = "Bravo"    │                ║
║    │ _hitPoints = 10    │                ║
║    │ _energyPoints = 10 │                ║
║    │ _attackDamage = 0  │                ║
║    └────────────────────┘                ║
║                                          ║
║  Step 2: Then build ScavTrap part        ║
║    ┌────────────────────┐                ║
║    │ ScavTrap("Bravo")  │ ← constructor  ║
║    │ _hitPoints = 100   │ ← overwrite!   ║
║    │ _energyPoints = 50 │ ← overwrite!   ║
║    │ _attackDamage = 20 │ ← overwrite!   ║
║    └────────────────────┘                ║
╚══════════════════════════════════════════╝
```

### Destruction: DERIVED FIRST, then BASE (reverse!)

```
} // b goes out of scope

╔══════════════════════════════════════════╗
║ DESTRUCTION ORDER (top-down teardown)    ║
║                                          ║
║  Step 1: Destroy ScavTrap part           ║
║    "ScavTrap destructor called"          ║
║                                          ║
║  Step 2: Destroy ClapTrap part           ║
║    "ClapTrap destructor called"          ║
╚══════════════════════════════════════════╝
```

**Why this order?** Think of it like building a house:
- **Construction:** Foundation (ClapTrap) first, then walls (ScavTrap). You can't build walls without a foundation.
- **Destruction:** Remove walls (ScavTrap) first, then foundation (ClapTrap). The walls might depend on the foundation, so you can't remove it first.

### How to call the base constructor:

```cpp
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
//                                            ^^^^^^^^^^^^
//                 This calls ClapTrap's parameterized constructor FIRST
{
    _hitPoints = 100;   // Then we customize ScavTrap's values
    _energyPoints = 50;
    _attackDamage = 20;
}
```

If you don't write `: ClapTrap(name)`, the compiler will call `ClapTrap()` (default constructor) automatically — and the name would be "default" instead of "Bravo"!

---

## 7. FUNCTION HIDING vs OVERRIDING

In this project, ScavTrap declares its own `attack()`:

```cpp
// ClapTrap has:
void ClapTrap::attack(const std::string &target);  // prints "ClapTrap ... attacks"

// ScavTrap has:
void ScavTrap::attack(const std::string &target);  // prints "ScavTrap ... attacks"
```

This is **name hiding**, NOT true polymorphic overriding:

```
┌─────────────────────────────────────────────────────┐
│            NAME HIDING (what we use)                │
├─────────────────────────────────────────────────────┤
│                                                     │
│  ScavTrap b("B");                                   │
│  b.attack("X");        → calls ScavTrap::attack  ✅│
│                                                     │
│  ClapTrap &ref = b;                                 │
│  ref.attack("X");      → calls ClapTrap::attack  ⚠️│
│                           (base version, not child) │
│                                                     │
├─────────────────────────────────────────────────────┤
│         TRUE OVERRIDING (needs virtual)             │
├─────────────────────────────────────────────────────┤
│                                                     │
│  virtual void attack();   ← in base class           │
│                                                     │
│  ClapTrap &ref = b;                                 │
│  ref.attack("X");      → calls ScavTrap::attack  ✅│
│                           (follows actual type)     │
└─────────────────────────────────────────────────────┘
```

We don't use `virtual` here because the subject doesn't require polymorphism. We always call methods on the concrete type directly.

---

## 8. THE DIAMOND PROBLEM (ex03)

This is the **hardest concept** in the module. Let's build it step by step.

### The Problem: Without Virtual Inheritance

DiamondTrap inherits from BOTH FragTrap and ScavTrap. Both inherit from ClapTrap. So DiamondTrap would get **two copies** of ClapTrap:

```
WITHOUT virtual inheritance:

    ClapTrap (copy 1)       ClapTrap (copy 2)
    _name = ?               _name = ?
    _hitPoints = ?           _hitPoints = ?
         |                        |
     FragTrap                 ScavTrap
         |                        |
         └────────┬───────────────┘
            DiamondTrap

    d._hitPoints → AMBIGUOUS! Which copy? ❌
    d._name      → AMBIGUOUS! Which copy? ❌
```

### The Solution: Virtual Inheritance

```cpp
class ScavTrap : virtual public ClapTrap    // ← "virtual" keyword
class FragTrap : virtual public ClapTrap    // ← "virtual" keyword
```

```
WITH virtual inheritance:

              ClapTrap (ONLY ONE copy!)
              _name = "Diamond_clap_name"
              _hitPoints
             /          \
         FragTrap      ScavTrap
             \          /
            DiamondTrap

    d._hitPoints → Clear! Only one copy ✅
    d._name      → Clear! Only one copy ✅
```

### The Trick: Who Constructs the Virtual Base?

Normally, FragTrap constructs its own ClapTrap, and ScavTrap constructs its own ClapTrap. But with virtual inheritance, **only the most-derived class** (DiamondTrap) constructs the shared ClapTrap:

```cpp
DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"),   // ← DiamondTrap constructs ClapTrap!
      FragTrap(name),                   // ← FragTrap's ClapTrap call is IGNORED
      ScavTrap(name)                    // ← ScavTrap's ClapTrap call is IGNORED
```

```
CONSTRUCTION ORDER for DiamondTrap("Diamond"):

Step 1: ClapTrap("Diamond_clap_name")    ← virtual base, constructed FIRST
         "ClapTrap parameterized constructor called"

Step 2: FragTrap("Diamond")               ← first parent
         (does NOT call ClapTrap again!)
         "FragTrap parameterized constructor called"

Step 3: ScavTrap("Diamond")               ← second parent
         (does NOT call ClapTrap again!)
         "ScavTrap parameterized constructor called"

Step 4: DiamondTrap("Diamond")            ← most derived
         "DiamondTrap parameterized constructor called"
```

```
DESTRUCTION ORDER (exact reverse):

Step 1: ~DiamondTrap()
Step 2: ~ScavTrap()
Step 3: ~FragTrap()
Step 4: ~ClapTrap()       ← virtual base destroyed LAST
```

---

## 9. NAME SHADOWING (DiamondTrap::_name vs ClapTrap::_name)

DiamondTrap has its **own** `_name` attribute that **shadows** the inherited one:

```cpp
class ClapTrap
{
    protected:
        std::string _name;       // ← ClapTrap's _name
};

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _name;       // ← DiamondTrap's OWN _name (same variable name!)
};
```

```
Memory layout of DiamondTrap d("Diamond"):

┌─────────────────────────────────────────┐
│ ClapTrap part:                          │
│   _name = "Diamond_clap_name"  ← base  │
│   _hitPoints = 100                      │
│   _energyPoints = 50                    │
│   _attackDamage = 30                    │
├─────────────────────────────────────────┤
│ DiamondTrap part:                       │
│   _name = "Diamond"   ← shadows base!  │
└─────────────────────────────────────────┘
```

```cpp
void DiamondTrap::whoAmI()
{
    // _name          → finds DiamondTrap::_name first = "Diamond"
    // ClapTrap::_name → explicitly asks for base    = "Diamond_clap_name"

    std::cout << "I am " << _name
              << ", ClapTrap name is " << ClapTrap::_name;
}
// Output: "I am Diamond, ClapTrap name is Diamond_clap_name"
```

The `-Wshadow` flag **warns** about this. `-Wno-shadow` **suppresses** it because the subject intentionally requires this design.

---

## 10. `using` DECLARATION

```cpp
class DiamondTrap : public FragTrap, public ScavTrap
{
    public:
        using ScavTrap::attack;  // ← resolve ambiguity
};
```

DiamondTrap inherits `attack()` from both paths. Without `using`, calling `d.attack()` would be **ambiguous**:

```
Without "using":

    ClapTrap::attack()
         /          \
FragTrap::attack()   ScavTrap::attack()
         \          /
    DiamondTrap::attack()  → Which one?? ❌ AMBIGUOUS

With "using ScavTrap::attack":

    DiamondTrap::attack()  → ScavTrap::attack() ✅ CLEAR
```

---

## 11. `const std::string &` — References and const

You'll see this pattern everywhere:

```cpp
void attack(const std::string &target);
//          ^^^^^             ^
//          can't modify     reference (no copy)
```

```
BY VALUE (without &):                BY REFERENCE (with &):

void f(std::string target)           void f(const std::string &target)

  ┌────────┐    ┌────────┐            ┌────────┐
  │"Alpha" │ →  │"Alpha" │ copy!      │"Alpha" │ ← target IS this
  └────────┘    └────────┘            └────────┘
  original      copy (waste!)         no copy! efficient!
```

- `&` means **reference** — alias for the original, no copying (efficient)
- `const` means we promise **not to modify** the original (safe)

---

## 12. `this` POINTER

Every member function has a hidden `this` pointer that points to the current object:

```cpp
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
    if (this != &rhs)     // Are we assigning to ourselves?
    //  ^^^^    ^^^^
    //  pointer  address of rhs
    //  to self
    {
        _name = rhs._name;
    }
    return *this;         // Return the current object
    //     ^^^^^
    //     dereference this pointer → the object itself
}
```

```
ClapTrap a("A"), b("B");

b = a;
// Inside operator=:
//   this  → points to b
//   &rhs  → points to a
//   this != &rhs → true → proceed with assignment

a = a;
// Inside operator=:
//   this  → points to a
//   &rhs  → points to a
//   this != &rhs → false → SKIP (self-assignment protection)
```

---

## 13. INCLUDE GUARDS

```cpp
#ifndef CLAPTRAP_HPP     // "if NOT defined"
# define CLAPTRAP_HPP    // "now define it"

class ClapTrap { ... };

#endif                   // "end if"
```

```
Scenario: DiamondTrap.hpp includes both ScavTrap.hpp and FragTrap.hpp,
          both of which include ClapTrap.hpp

WITHOUT include guards:

  DiamondTrap.hpp
    → #include "ScavTrap.hpp"
        → #include "ClapTrap.hpp"    ← class ClapTrap defined ✅
    → #include "FragTrap.hpp"
        → #include "ClapTrap.hpp"    ← class ClapTrap defined AGAIN ❌
                                        COMPILATION ERROR: redefinition!

WITH include guards:

  DiamondTrap.hpp
    → #include "ScavTrap.hpp"
        → #include "ClapTrap.hpp"
            CLAPTRAP_HPP not defined → enter → define it → class ClapTrap ✅
    → #include "FragTrap.hpp"
        → #include "ClapTrap.hpp"
            CLAPTRAP_HPP already defined → SKIP entire file ✅
```

---

## 14. MAKEFILE EXPLAINED

```makefile
NAME = claptrap                              # Output binary name

CXX = c++                                   # Compiler command
CXXFLAGS = -Wall -Wextra -Werror -std=c++98  # Compiler flags

SRCS = main.cpp ClapTrap.cpp                 # Source files
OBJS = $(SRCS:.cpp=.o)                       # .cpp → .o replacement
# OBJS = main.o ClapTrap.o

all: $(NAME)                # Default target → builds the binary

$(NAME): $(OBJS)            # Binary depends on all .o files
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)   # Link step

%.o: %.cpp                  # Pattern rule: any .o depends on matching .cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	#                   -c = compile only, don't link
	#                   $< = the .cpp file (prerequisite)
	#                   $@ = the .o file (target)

clean:                      # Remove object files
	rm -f $(OBJS)

fclean: clean               # Remove objects AND binary
	rm -f $(NAME)

re: fclean all              # Rebuild from scratch

.PHONY: all clean fclean re # These aren't real files
```

### Compilation Pipeline:

```
Source Files          Compile (-c)         Object Files         Link
┌──────────┐        ┌──────────┐        ┌──────────┐       ┌──────────┐
│ main.cpp │───────→│ main.o   │───┐    │          │       │          │
└──────────┘        └──────────┘   ├───→│ claptrap │──────→│ ./claptrap│
┌──────────┐        ┌──────────┐   │    │ (binary) │       │ (run it!)│
│ClapTrap. │───────→│ClapTrap.o│───┘    │          │       │          │
│   cpp    │        └──────────┘        └──────────┘       └──────────┘
└──────────┘
```

### Compiler flags:

```
-Wall    → Enable most warning messages
           "Missing return", "unused variable", etc.

-Wextra  → Enable extra warnings beyond -Wall
           "Unused parameter", "empty body in if", etc.

-Werror  → Treat ALL warnings as ERRORS
           Code won't compile if there's even one warning!

-std=c++98 → Use C++98 standard (no auto, nullptr, range-for, etc.)

-Wshadow   → Warn when a variable shadows another (ex03)
-Wno-shadow → Suppress shadow warnings (because we intentionally shadow)
```

---

## 15. COMPLETE INHERITANCE HIERARCHY

```
                         ┌──────────────────────┐
                         │      ClapTrap        │
                         │  (Base class)        │
                         │                      │
                         │  protected:          │
                         │    _name             │
                         │    _hitPoints = 10   │
                         │    _energyPoints = 10│
                         │    _attackDamage = 0 │
                         │                      │
                         │  public:             │
                         │    attack()          │
                         │    takeDamage()      │
                         │    beRepaired()      │
                         └──────────┬───────────┘
                                    │
              ┌─────────────────────┼─────────────────────┐
              │ virtual             │                      │ virtual
    ┌─────────┴──────────┐         │          ┌───────────┴────────────┐
    │     FragTrap       │         │          │      ScavTrap          │
    │                    │         │          │                        │
    │  HP = 100          │         │          │  HP = 100              │
    │  EP = 100          │         │          │  EP = 50               │
    │  AD = 30           │         │          │  AD = 20               │
    │                    │         │          │                        │
    │  highFivesGuys()   │         │          │  attack() ← overrides │
    └─────────┬──────────┘         │          │  guardGate()          │
              │                    │          └───────────┬────────────┘
              │                    │                      │
              └────────────┬───────┘──────────────────────┘
                           │
                ┌──────────┴───────────┐
                │    DiamondTrap       │
                │                      │
                │  private:            │
                │    _name (shadows!)  │
                │                      │
                │  HP from FragTrap    │ = 100
                │  EP from ScavTrap    │ = 50
                │  AD from FragTrap    │ = 30
                │  attack() from Scav  │
                │                      │
                │  whoAmI()            │
                │  + guardGate()       │ inherited
                │  + highFivesGuys()   │ inherited
                └──────────────────────┘
```
