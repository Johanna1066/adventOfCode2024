// day6.cpp
// https://adventofcode.com/2024/day/6

#include "day6.h"
#include "../functions.h"
#include <iostream>
#include <string>
#include <vector>

int part1(std::vector<std::vector<char>> map, std::pair<int,int>& startPosition) {

    int sum{};

    // N, E, S, W ({y,x})
    std::pair<int,int> directions[4]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
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

bool part2(std::vector<std::vector<char>> map, std::pair<int,int>& startPosition) {

    int itterations{};

    // N, E, S, W ({y,x})
    std::pair<int,int> directions[4]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int direction = 0;

    // first = y-coordinate, second = x-coordinate
    std::pair<int,int> currentPosition = startPosition;

    char currentChar = map[currentPosition.first][currentPosition.second];
    char nextChar =  map[currentPosition.first + directions[direction].first]
                        [currentPosition.second + directions[direction].second];

    do {
        nextChar =  map[currentPosition.first + directions[direction].first]
                       [currentPosition.second + directions[direction].second];

        if(nextChar == '-'){
            return true;
        }

        if (nextChar == '#'){
            direction = ( ( direction + 1 ) % 4 );
            char nextNextChar =  map[currentPosition.first + directions[direction].first]
                                [currentPosition.second + directions[direction].second];
            if(nextNextChar == '#'){
                direction = ( ( direction + 1 ) % 4 );
            }
        }

        if (itterations > 10000){
            return false;
        }

        // Update position and the char in that position
        currentPosition.first = currentPosition.first + directions[direction].first;
        currentPosition.second = currentPosition.second + directions[direction].second;
        currentChar = map[currentPosition.first][currentPosition.second];

        itterations++;

    } while (currentChar != '-');

    return true;
}

void day6()
{
    std::string fileURL = "../day6/inputDay6.txt";
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


for (size_t i = 0; i < map.size(); ++i) {
    auto& y = map[i];

    if (y[3] == '-')
        continue;

    for (size_t j = 0; j < y.size(); ++j) {
        auto& x = y[j];

        if (x == '.') {
            x = '#';

            if (!part2(map, startPosition)) {
                sum2++;
                std::cout << "Found loop at: (" << i << ", " << j << ")" << std::endl;
            }
            x = '.';
        }
    }
}

    std::cout << "part 1: " << sum1 << std::endl;
    std::cout << "part 2: " << sum2 << std::endl;
}