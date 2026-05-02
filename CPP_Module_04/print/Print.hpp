/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:00:00 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 10:21:27 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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