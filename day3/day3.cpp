// day3.cpp
// https://adventofcode.com/2024/day/3

#include "day3.h"
#include "../functions.h"
#include <iostream>
#include <string>
#include <regex>

int part1(std::string line) {
    int sum{};
    std::string newLine;
    for (auto &a : line) {
        if (a == 'm')
            newLine += ' ';
        newLine += a;
        if (a == ')')
            newLine += ' ';
    }

    std::regex matchExpression("mul\\(([1-9]\\d*),([1-9]\\d*)\\)");

    std::smatch matches;
    std::string::const_iterator searchStart(newLine.cbegin());
    while (std::regex_search(searchStart, newLine.cend(), matches, matchExpression)){
        std::cout << "match: " << matches.str() << std::endl; 
        std::string current = matches.str();
        if (matches.size() == 3){ // Ensure there are 3 matches: the whole match and two groups
            int firstInt = std::stoi(matches[1].str());
            int secondInt = std::stoi(matches[2].str());
            int product = firstInt * secondInt;
            sum += product; 

            searchStart = matches.suffix().first;
        }
    }

    return sum;
}

int part2(std::string line) {
    return 1;
}

void day3()
{
    std::string fileURL = "../day3/inputDay3.txt";
    std::ifstream input = readFile(fileURL);

    std::string line;
    int sum1{};

    while (std::getline(input, line)){
        sum1 += part1(line);
    }

    std::cout << "part 1: " << sum1 << std::endl;
}