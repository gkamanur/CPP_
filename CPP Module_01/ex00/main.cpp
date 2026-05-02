/* ************************************************************************** */
/*                                                                            */
/*   main.cpp - Testing Stack vs Heap allocation                              */
/*                                                                            */
/*   Run this program and WATCH THE OUTPUT carefully!                         */
/*   Notice WHEN each zombie is destroyed.                                    */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::cout << "\n========== HEAP ALLOCATION TEST ==========" << std::endl;
    std::cout << "Creating zombie on HEAP with newZombie()..." << std::endl;
    
  
    Zombie* heapZombie = newZombie("HeapZombie");
    
    std::cout << "\nHeap zombie announces:" << std::endl;
    heapZombie->announce();  // Use -> because heapZombie is a POINTER
    
    std::cout << "\nHeap zombie still alive... we control its lifetime!" << std::endl;
    std::cout << "Now we delete it:" << std::endl;
    delete heapZombie;  // WE must delete it, or memory leak!
    
    
    std::cout << "\n========== STACK ALLOCATION TEST ==========" << std::endl;
    std::cout << "Creating zombie on STACK with randomChump()..." << std::endl;
    

    randomChump("StackZombie");
    
    std::cout << "Back in main - stack zombie is ALREADY GONE!" << std::endl;
    
    
    std::cout << "\n========== COMPARISON ==========" << std::endl;
    std::cout << "Let's create both types and see the difference:\n" << std::endl;
    
    Zombie* longLivedZombie = newZombie("LongLived");
    
    // Create a stack zombie - it dies immediately after this scope
    {
        std::cout << "\n--- Entering inner scope ---" << std::endl;
        Zombie shortLivedZombie("ShortLived");  // Stack allocation
        shortLivedZombie.announce();
        std::cout << "--- Exiting inner scope (ShortLived will die) ---" << std::endl;
    }  // ShortLived is destroyed HERE automatically!
    
    std::cout << "\nShortLived is gone, but LongLived is still here:" << std::endl;
    longLivedZombie->announce();
    
    std::cout << "\nNow we delete LongLived:" << std::endl;
    delete longLivedZombie;
    
    std::cout << "\n========== END OF PROGRAM ==========" << std::endl;
    return 0;
}

