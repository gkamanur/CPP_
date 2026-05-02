/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:45:16 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/07 16:04:47 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data originalData(42, "Hello, Serialization!", 3.14159);
    
    std::cout << "===ORIGINAL DATA=====" << std::endl;
    std::cout << "Address of originalData: " << &originalData << std::endl;
    std::cout << "Data.id: " << originalData.id << std::endl;
    std::cout << "Data.name: " << originalData.name << std::endl;
    std::cout << "Data.value: " << originalData.value << std::endl;
    std::cout << std::endl;
    
    uintptr_t raw = Serializer::serialize(&originalData);
    std::cout << "===AFTER SERIALIZATION===" << std::endl;
    std::cout << "raw value (as integer): " << raw << std::endl;
    std::cout << "raw value (as hex): 0x" << std::hex << raw << std::dec <<std::endl;
    std::cout << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "=====AFTER DESERIALIZATION====" << std::endl;
    std::cout << "Address of Desrialized Data: " << deserializedData << std::endl;
    std::cout << "Data.id: " << deserializedData->id << std::endl;
    
    std::cout << "Data.name: " << deserializedData->name << std::endl;
    std::cout << "Data.value: " << deserializedData->value << std::endl;
    std::cout << std::endl;

    std::cout << "=====VERIFICATION=====" << std::endl;
    if (deserializedData == &originalData)
        std::cout << "SUCCESS: desrialize() returned the original pointer!" <<std::endl;
    else
        std::cout << "Fail: Pointers do not match!" << std::endl;
    
    deserializedData->value = 99.99;
    std::cout << "Modified through deserialized pointer...." << std::endl;
    std::cout << "Original data.value is now: " << originalData.value << std::endl;

    return 0;
}
