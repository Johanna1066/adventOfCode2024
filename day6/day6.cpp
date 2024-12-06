// day6.cpp
// https://adventofcode.com/2024/day/6

#include "day6.h"
#include "../functions.h"
#include <iostream>
#include <string>

void part1() {
}

void part2() {
}

void day6()
{
    std::string fileURL = "../day6/inputDay6.txt";
    std::ifstream input = readFile(fileURL);

    std::string line;
    int sum1{}, sum2{};

    while (std::getline(input, line)){
        
    }
    input.close();

    std::cout << "part 1: " << sum1 << std::endl;
    std::cout << "part 2: " << sum2 << std::endl;
}