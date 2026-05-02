/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:13:29 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/24 17:13:34 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Check file type
bool isHeader(const std::string& file)
{
    return file.size() >= 4 && file.substr(file.size() - 4) == ".hpp";
}

bool isSource(const std::string& file)
{
    return file.size() >= 4 && file.substr(file.size() - 4) == ".cpp";
}

// Write file content
void writeFile(std::ofstream& out, const std::string& filename, bool skipLocalIncludes)
{
    std::ifstream in(filename.c_str());
    if (!in)
    {
        std::cerr << "Error opening: " << filename << std::endl;
        return;
    }

    out << "\n// ===== " << filename << " =====\n\n";

    std::string line;
    while (std::getline(in, line))
    {
        // Skip local includes like #include "Animal.hpp"
        if (skipLocalIncludes && line.find("#include \"") != std::string::npos)
            continue;

        out << line << "\n";
    }
}

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " output.cpp files...\n";
        return 1;
    }

    std::ofstream out(argv[1]);
    if (!out)
    {
        std::cerr << "Error: cannot create output file\n";
        return 1;
    }

    std::vector<std::string> headers;
    std::vector<std::string> sources;

    // Separate files
    for (int i = 2; i < argc; i++)
    {
        std::string file = argv[i];

        if (isHeader(file))
            headers.push_back(file);
        else if (isSource(file))
            sources.push_back(file);
    }

    // =========================
    // 1️⃣ HEADERS FIRST
    // =========================
    out << "// ===== COMBINED HEADERS =====\n";

    for (size_t i = 0; i < headers.size(); i++)
        writeFile(out, headers[i], false);

    // =========================
    // 2️⃣ SOURCES AFTER
    // =========================
    out << "\n// ===== COMBINED SOURCES =====\n";

    for (size_t i = 0; i < sources.size(); i++)
        writeFile(out, sources[i], true);

    out.close();

    std::cout << "✅ Done: " << argv[1] << std::endl;
    return 0;
}