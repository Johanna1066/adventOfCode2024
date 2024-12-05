// day5.cpp
// https://adventofcode.com/2024/day/5

#include "day5.h"
#include "../functions.h"
#include <iostream>
#include <string>
#include <vector>

bool part1(std::vector<std::pair<std::string, std::string>>& rules, std::string& update) {

    int sum{};

        for (auto rule : rules){
            std::size_t firstPos = update.find(rule.first);
            std::size_t secondPos = update.find(rule.second);

            if(firstPos != std::string::npos && secondPos != std::string::npos){

                if(firstPos > secondPos){
                    return false;
                }
            }
        }
        return true;
}

int part2(std::vector<std::pair<std::string, std::string>>& rules, std::string& update) {

    int sum{};

        while(!part1(rules, update)){

            for (auto rule : rules){
                std::size_t firstPos = update.find(rule.first);
                std::size_t secondPos = update.find(rule.second);

                if(firstPos != std::string::npos && secondPos != std::string::npos){

                    if(firstPos > secondPos){
                        std::string firstNo = update.substr(firstPos,2);
                        std::string secondNo = update.substr(secondPos,2);
                        update.replace(secondPos, 2, firstNo);
                        update.replace(firstPos, 2, secondNo);
                    }
                }
            }
        }

        int middlePos = update.size()/2;
        std::string middleStr = update.substr(middlePos-1, 2);
        int middleInt = std::stoi(middleStr);
        sum += middleInt;
        return sum;
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
            std::pair<std::string, std::string> temp; 

            temp.first = line.substr(0,2);
            temp.second = line.substr(3,2);

            rules.push_back(temp);
        }
        else if (line == "\r"){
            continue;
        } else {
            std::string temp = line; 
            updates.push_back(temp);
        }
    }
    input.close();

    for (auto update : updates){

        if(part1(rules, update)){
            int middlePos = update.size()/2;
            std::string middleStr = update.substr(middlePos-1, 2);
            int middleInt = std::stoi(middleStr);
            sum1 += middleInt;
        } else {
            sum2 += part2(rules, update);
        }
    }

    std::cout << "part 1: " << sum1 << std::endl;
    std::cout << "part 2: " << sum2 << std::endl;
}