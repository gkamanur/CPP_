#include <iostream>
# include "Array.hpp"
#include <cstdlib>  // for srand(), rand()
#include <ctime> 

#define MAX_VAL 7
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "\n Numbers: ";
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n Mirror: ";
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << mirror [i] << " ";
    }
    //SCOPE
    std::cout << "\n \n ";
    {
        Array<int> tmp = numbers;
        for (int i = 0; i < MAX_VAL; i++)
        {
            std::cout << tmp [i] << " ";
        }
        std::cout << "\n \n ";
        Array<int> test(tmp);
        for (int i = 0; i < MAX_VAL; i++)
        {
            std::cout << test [i] << " ";
        }
    }
    std::cout << std::endl <<std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\nTest: ";
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n Numbers: ";
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << numbers[i] << " ";
    }
     std::cout << std::endl;
    delete [] mirror;//
    return 0;
}