/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 11:21:04 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/12 19:56:16 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "iter.hpp"

void printchar(const char& c)
{
    std::cout << c;
}

int main ()
{
    int intArr[] = {1, 2, 3, 4, 5};
    size_t intlen = sizeof(intArr) / sizeof(intArr[0]);

    std::cout << "Original int array: ";
    iter(intArr, intlen, print<int>);
    std::cout << std::endl;

    iter(intArr, intlen, increment<int>);
    std::cout << "After Increment: ";
    iter(intArr, intlen, print<int>);

    std::string strArr[] = {"hello", "my", "friend"};
    size_t strlen = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << std::endl << "\nString Array: ";
    iter(strArr, strlen, print<std::string>);
    std::cout << std::endl;

    const char constArr[] = {'A', 'B', 'C', 'D'};
    size_t constlen = sizeof(constArr) / sizeof(constArr[0]);
    
    std::cout << std::endl << "Const char Array: ";
    iter(constArr, constlen, printchar);
    std::cout << std::endl;

    return 0;
}
