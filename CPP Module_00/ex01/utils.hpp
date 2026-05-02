#pragma once
#include <iostream>

class Utils {
public:
    template <typename T>
    static void print(const T& value) {
        std::cout << value;
    }

    template <typename T>
    static void println(const T& value) {
        print(value);
        std::cout << std::endl;
    }

    template <typename T>
    static void printError(const T& error) {
        std::cout << "ERROR: ";
        print(error);
        std::cout << std::endl;
    }
};