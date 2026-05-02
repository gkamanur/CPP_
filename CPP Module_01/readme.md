Ex00: BraiiiiiiinnnzzzZ — Stack vs heap allocation. 
You're forced to think about when to use new (heap) vs just declaring an object locally (stack). 
newZombie needs heap because it must survive past the function scope. randomChump can use the stack since it only needs to exist momentarily.
The destructor message helps you see exactly when objects die.

Ex01: Moar brainz! — Array allocation with new[] and the matching delete[]. 
The key lesson is that allocating N objects at once is different from N separate allocations, and you must use delete[] not just delete or you get undefined behavior.

Ex02: HI THIS IS BRAIN — Demystifying references. By printing the addresses of a variable, 
a pointer to it, and a reference to it, you discover that a reference is just the same address — 
it's syntactic sugar for a pointer that's always valid and never needs dereferencing syntax.

Ex03: Unnecessary violence — When to use a reference vs a pointer to hold a member. 
HumanA always has a weapon (given at construction) → use a reference since it can never be null and never changes. 
HumanB may not have one initially → use a pointer since it needs to be nullable/settable later.

Ex04: Sed is for losers — File I/O with fstream and string manipulation without replace. You learn find() + erase() + insert() as the manual alternative, plus proper stream error handling.

Ex05: Harl 2.0 — Pointers to member functions. Instead of a chain of if/else to dispatch to the right method, 
you build an array of function pointers and look up the right one by index. This is the foundation of how vtables and dispatch tables work.

Ex06: Harl filter — The switch statement with fall-through.
The trick is that once you match a level (e.g. WARNING), you don't break, so execution falls through and prints all higher-severity messages too. 
This is the idiomatic C++ way to handle ordered/cascading cases.
The module as a whole is building your mental model of memory (where things live and who owns them), 
references vs pointers (and when each is appropriate), and function dispatch mechanisms — all foundational before you get into OOP patterns in later modules.
