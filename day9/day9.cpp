// day9.cpp
// https://adventofcode.com/2024/day/9

#include "day9.h"
#include "../functions.h"
#include <iostream>
#include <string>

void part1() {
}

void part2() {
}

void day9()
{
    std::string fileURL = "../day9/inputDay9.txt";
    std::ifstream input = readFile(fileURL);

    std::string line;
    int sum1{}, sum2{};

    while (std::getline(input, line)){
        
    }
    input.close();

    std::cout << "part 1: " << sum1 << std::endl;
    std::cout << "part 2: " << sum2 << std::endl;
}