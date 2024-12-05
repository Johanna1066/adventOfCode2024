// day5.cpp
// https://adventofcode.com/2024/day/5

#include "day5.h"
#include "../functions.h"
#include <iostream>
#include <string>
#include <vector>

bool part1(std::vector<std::pair<std::string, std::string>>& rules, std::string& update) {

    int sum{};
    //std::cout << update << std::endl;

        for (auto rule : rules){
            std::size_t firstPos = update.find(rule.first);
            std::size_t secondPos = update.find(rule.second);
            //std::cout << "  Rule: " << rule.first << ", " << rule.second << std::endl; 
            //std::cout << "in update: " << update << std::endl;

            //std::cout << "firstPos = " << firstPos << "| secondPos = " << secondPos << std::endl;
            if(firstPos != std::string::npos && secondPos != std::string::npos){
                //std::cout << "both were found!" << std::endl;
                if(firstPos > secondPos){
                    //std::cout << "the second was before the first" << std::endl;
                    return false;
                }
            }
        }
        return true;
}

void part2(){

}

void day5()
{
    std::string fileURL = "../day5/inputDay5.txt";
    std::ifstream input = readFile(fileURL);

    std::string line;
    int sum1{}, sum2{};

    std::vector<std::pair<std::string, std::string>> rules;
    std::vector<std::string> updates;


    while (std::getline(input, line)){
        if (line.find('|') != std::string::npos){
            // std::cout << "rules: " << line << std::endl;
            std::pair<std::string, std::string> temp; 

            // std::cout << numberStr << std::endl;
            temp.first = line.substr(0,2);
            temp.second = line.substr(3,2);

            rules.push_back(temp);
        }
        else if (line == "\r"){
            continue;
        } else {
            //std::cout << "update: " << line << std::endl;
            std::string temp = line; 
            updates.push_back(temp);
        }
    }
    input.close();

    for(auto update : updates){
        //std::cout << update << std::endl;
    }

    for (auto update : updates){
        // std::cout << update << std::endl;
        if(part1(rules, update)){
            int middlePos = update.size()/2;
            std::string middleStr = update.substr(middlePos-1, 2);
            int middleInt = std::stoi(middleStr);
            sum1 += middleInt;
        }
    }

    std::cout << "part 1: " << sum1 << std::endl;
    std::cout << "part 2: " << sum2 << std::endl;
}