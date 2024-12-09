// day7.cpp
// https://adventofcode.com/2024/day/7

#include "day7.h"
#include "../functions.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>


long part1(std::vector<std::pair<long, std::vector<long>>>& equations) {
    long sum{};
    for(auto& equation : equations){
        long length = equation.second.size();
        std::vector<long> results;

        for(auto& term : equation.second){

            if(results.size() == 0){
                results.push_back(term);
            } else {
                std::vector<long> temp;
                for (auto result : results){
                    long mult = result*term;
                    long add = result + term;
                    temp.push_back(mult);
                    temp.push_back(add);
                }
                results = temp;
            }
        }
        auto pos = find(results.begin(), results.end(), equation.first);
        if (pos != results.end()) {
            sum += equation.first;
        }
    }
    return sum;
}

void part2() {
}

void day7()
{
    std::string fileURL = "../day7/inputDay7.txt";
    std::ifstream input = readFile(fileURL);

    std::string line;
    long sum1{}, sum2{};

    std::vector<std::pair<long, std::vector<long>>> equations;

    while (std::getline(input, line)){
        std::pair<long, std::vector<long>> temp;
       
        size_t pos = line.find(':');

        std::string first = line.substr(0, pos);
        temp.first = std::stoul(first);

        long length = line.size();

        std::string second = line.substr(pos+1, length-pos);
        
        std::stringstream ss(second);
        long found;

        while (ss >> found) {
            temp.second.push_back(found);
        }

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
    
    
    sum1 = part1(equations);


    std::cout << "part 1: " << sum1 << std::endl;
    std::cout << "part 2: " << sum2 << std::endl;
}