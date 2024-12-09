// day7.cpp
// https://adventofcode.com/2024/day/7

#include "day7.h"
#include "../functions.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


void part1() {
}

void part2() {
}

void day7()
{
    std::string fileURL = "../day7/testInputDay7.txt";
    std::ifstream input = readFile(fileURL);

    std::string line;
    int sum1{}, sum2{};

    std::vector<std::pair<int, std::vector<int>>> equations;

    while (std::getline(input, line)){
        std::pair<int, std::vector<int>> temp;
        std::vector<int> args;
        std::stringstream ss(line);
        int found;

        size_t pos = line.find(':');

        std::string first = line.substr(0, pos);

        std::string second = line.substring(pos,);


        ss >> found;

        temp.first = found;



       

        



        while (ss >> found) {
            args.push_back(found);
            std::cout << "arg: " << found << std::endl; 
        }

        temp.second = args;

        equations.push_back(temp);
    }
    input.close();

/*
    for (auto equation : equations){
        std::cout << "sum: " << equation.first << "  operands: " << equation.second.size() << std::endl;

        for (auto term : equation.second){
            std::cout << "- " << term << std::endl;
        }
    }
*/


    std::cout << "part 1: " << sum1 << std::endl;
    std::cout << "part 2: " << sum2 << std::endl;
}