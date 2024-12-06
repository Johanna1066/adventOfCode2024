// day6.cpp
// https://adventofcode.com/2024/day/6

#include "day6.h"
#include "../functions.h"
#include <iostream>
#include <string>
#include <vector>

int part1(std::vector<std::vector<char>> map, std::pair<int,int>& startPosition) {

    int sum{};

    // N, E, S, W
    std::pair<int,int> directions[4]{{-1,0},{0,1},{1,0},{0,-1}};
    int direction = 0;

    // first = y-coordinate, second = x-coordinate
    std::pair<int,int> currentPosition = startPosition;

    char currentChar = map[currentPosition.first][currentPosition.second];
    char nextChar =  map[currentPosition.first + directions[direction].first]
                        [currentPosition.second + directions[direction].second];

    do {
        nextChar =  map[currentPosition.first + directions[direction].first]
                       [currentPosition.second + directions[direction].second];

        if (currentChar == '.'){
            map[currentPosition.first][currentPosition.second] = 'X';
            sum ++;
        }

        if(nextChar == '-'){
            return sum;
        }

        if (nextChar == '#'){
            direction = ( ( direction + 1 ) % 4 );
        }

        // Update position and the char in that position
        currentPosition.first = currentPosition.first + directions[direction].first;
        currentPosition.second = currentPosition.second + directions[direction].second;
        currentChar = map[currentPosition.first][currentPosition.second];

    } while (currentChar != '-');

    return sum;
}

bool part2() {
    return true;
}

void day6()
{
    std::string fileURL = "../day6/testInputDay6.txt";
    std::ifstream input = readFile(fileURL);

    std::string line;
    int sum1{}, sum2{};

    std::vector<std::vector<char>> map;
    std::pair<int,int> startPosition{};
    int posX{1}, posY{1};

    while (std::getline(input, line)){
        std::vector<char> temp{};
        
        posX = 1;

        // Adding buffer around the puzzle input
        temp.push_back('-');

        for (auto a: line){

            if (a == '^'){
                startPosition.first = posY;
                startPosition.second = posX;
                temp.push_back('.');
                posX++;
                continue;
            }

            if (a == '\r'){
                continue;
            }

            temp.push_back(a);
            posX++;
        }

        // Adding buffer around the puzzle input
        temp.push_back('-');
    
        map.push_back(temp);

        posY++;
    }
    input.close();


    // Adding buffer around the entire puzzle input
    std::vector<char> temp(map[0].size(), '-');
    map.push_back(temp);
    map.insert(map.begin(), temp);
    

    sum1 = part1(map, startPosition);

    std::cout << "part 1: " << sum1 << std::endl;
    std::cout << "part 2: " << sum2 << std::endl;
}