/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 20:17:37 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/12 22:13:38 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"

int main()
{
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    
    Array<int> numbers(5);
    std::cout << "Numbers array size: " << numbers.size() << std::endl;
    
    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;
    std::cout << "Numbers: ";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    // Test copy constructor
    Array<int> copy(numbers);
    copy[0] = 999;
    
    std::cout << "\nOriginal after modifying copy: ";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    std::cout << "Copy: ";
    for (unsigned int i = 0; i < copy.size(); i++)
        std::cout << copy[i] << " ";
    std::cout << std::endl;
    
    // Test assignment operator
     Array<int> assigned;
     assigned = numbers;
     assigned[1] = 777;
     
     std::cout << "\nOriginal After Modifying assigned: ";
     for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
    
    std::cout << "Assigned: ";
    for (unsigned int i = 0; i < assigned.size(); i++)
        std::cout << assigned[i] << " ";
    std::cout << std::endl;
    
    const Array<int> constArr(numbers);
    std::cout << std::endl << "Const Array Access: ";
    for (unsigned int i = 0; i < constArr.size(); i++)
        std::cout << constArr[i] << " ";
    std::cout << std::endl;
    
    std::cout << std::endl << "Testing out of bounds: " <<std::endl;
    try
    {
        std::cout << numbers[100] <<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    Array <std::string> strings(3);
    
    strings[0] = "Hello";
    strings[1] = "my";
    strings[2] = "Friend";

    std::cout << "\nString array\n";
    for (unsigned int i = 0; i < strings.size(); i++)
        std::cout << strings[i] << " ";
    std::cout << std::endl;

    return (0);
    
}