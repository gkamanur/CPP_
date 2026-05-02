/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:24:43 by gkamanur          #+#    #+#             */
/*   Updated: 2026/02/23 20:00:56 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>    // For file streams
#include <string>

std::string replaceAll(const std::string& str, const std::string& from, const std::string& to)
{
    if (from.empty())
        return str;
    
    std::string result;
    size_t pos = 0;
    size_t found = 0;       
    
    while ((found = str.find(from, pos)) != std::string::npos)
    {
        // if length=6  substr(pos, length) takes index 0 → 5
        result += str.substr(pos, found - pos); 
        result += to;
        pos = found + from.length();

    }
    result += str.substr(pos);
    return result;
}

std::string replaceAll_(std::string str, const std::string& from, const std::string& to)
{
    if (from.empty())
        return str;

    size_t pos = 0;

    while ((pos = str.find(from, pos)) != std::string::npos)
    {
        str.replace(pos, from.length(), to);
        pos += to.length();  // Move past the replacement
    }

    return str;
}

int main(int argc, char** argv)
{
    // Check arguments
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        std::cerr << "  Replaces all occurrences of s1 with s2 in the file" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    if (s1.empty())
    {
        std::cerr << "Error: search string cannot be empty" << std::endl;
        return 1;
    }
    
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: could not open file '" << filename << "'" << std::endl;
        return 1;
    }
    
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: could not create file '" << outputFilename << "'" << std::endl;
        inputFile.close();
        return 1;
    }
    std::string line;
    bool firstLine = true;
    
    while (std::getline(inputFile, line))
    {
        // Add newline before each line (except the first)
        if (!firstLine)
            outputFile << '\n';
        firstLine = false;
        
        // Replace and write
        outputFile << replaceAll(line, s1, s2);
    }
    
    // Close files
    inputFile.close();
    outputFile.close();
    
    std::cout << "Created '" << outputFilename << "' with replacements" << std::endl;
    
    return 0;
}

