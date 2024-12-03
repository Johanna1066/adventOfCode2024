// day3.cpp
// https://adventofcode.com/2024/day/3

#include "day3.h"
#include "../functions.h"
#include <iostream>
#include <string>
#include <regex>

bool look{true};    // Has to be global for this solution to save 'do' or 'don't'
                    // between lines. There's def a better one but cba to 

int part1(std::string line) {

    int sum{};
    std::string formatedLine{};

    // formating the line with spaces for easier regex 
    for (auto &a : line) {
        if (a == 'm')
            formatedLine += ' ';
        formatedLine += a;
        if (a == ')')
            formatedLine += ' ';
    }

    std::regex matchExpression("mul\\(([1-9]\\d*),([1-9]\\d*)\\)");
    std::smatch matches{};
    std::string::const_iterator searchStart(formatedLine.cbegin());

    while (std::regex_search(searchStart, formatedLine.cend(), matches, matchExpression)){
        if (matches.size() == 3){ 
            int firstInt = std::stoi(matches[1].str());
            int secondInt = std::stoi(matches[2].str());
            sum += (firstInt * secondInt);

            searchStart = matches.suffix().first;
        }
    }
    return sum;
}

int part2(std::string line) {

    int sum{};
    std::string formattedLine{};

    // formating the line with spaces for easier regex 
    for (auto &a : line) {
        if (a == 'm' || a == 'd')
            formattedLine += ' ';
        formattedLine += a;
        if (a == ')')
            formattedLine += ' ';
    }

    std::regex matchExpression("mul\\(([1-9]\\d*),([1-9]\\d*)\\)|do\\(\\)|don't\\(\\)");
    std::smatch matches;
    std::string::const_iterator searchStart(formattedLine.cbegin());

    while (std::regex_search(searchStart, formattedLine.cend(), matches, matchExpression)) {
        std::string current = matches.str();
        searchStart = matches.suffix().first;

        if (current == "do()") {
            look = true;
            continue;
        }

        if (current == "don't()") {
            look = false;
            continue;
        }

        if (matches.size() == 3 && look) {
            int firstInt = std::stoi(matches[1].str());
            int secondInt = std::stoi(matches[2].str());
            sum += (firstInt * secondInt);
        }
    }
    return sum;
}

void day3()
{
    std::string fileURL = "../day3/inputDay3.txt";
    std::ifstream input = readFile(fileURL);

    std::string line;
    int sum1{}, sum2{};

    int lineNo{1};

    while (std::getline(input, line)){
        sum1 += part1(line);
        sum2 += part2(line);
    }

    input.close();

    std::cout << "part 1: " << sum1 << std::endl;
    std::cout << "part 2: " << sum2 << std::endl;
}