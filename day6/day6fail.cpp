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
            sum++;
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

struct node{
    int x{};
    int y{};
    bool direction[4]{false,false,false,false}; //N, E, S, W
};

bool part2(std::vector<std::vector<char>> map, std::pair<int,int>& startPosition, std::vector<node> nodes) {

    std::cout << "---Temp nodes---" << std::endl;
    for (auto node : nodes){
        std::cout << "node.x = " << node.x << "   -   node.y = " << node.y << "\n\n" << std::endl;
    }

    // N, E, S, W
    std::pair<int,int> directions[4]{{-1,0},{0,1},{1,0},{0,-1}};
    int direction = 0;

    // first = y-coordinate, second = x-coordinate
    std::pair<int,int> currentPosition = startPosition;

    char currentChar = map[currentPosition.first][currentPosition.second];
    char nextChar =  map[currentPosition.first + directions[direction].first]
                        [currentPosition.second + directions[direction].second];

    do {

        /*int i = 0;
        for(auto node : nodes){ 
            std::cout << "node" << i    <<  ": N-" << node.direction[0] 
                                        << "  E-" << node.direction[1] 
                                        << "  s-" << node.direction[2] 
                                        << "  w-" << node.direction[3]
                                        << std::endl;
            i++;
        }*/

        nextChar =  map[currentPosition.first + directions[direction].first]
                       [currentPosition.second + directions[direction].second];

        if(nextChar == '-'){
            return false;
        }

        if (nextChar == '#'){

            for (auto& node : nodes){ 
                if (node.x == currentPosition.second && node.y == currentPosition.first){

                    if (node.direction[direction]){
                        return true;
                    } else {
                        node.direction[direction] = true;
                    }
                }
            }

            direction = ( ( direction + 1 ) % 4 );
        }

        // Update to next position and the char in that position
        currentPosition.first = currentPosition.first + directions[direction].first;
        currentPosition.second = currentPosition.second + directions[direction].second;
        currentChar = map[currentPosition.first][currentPosition.second];

    } while (currentChar != '-');

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
    std::vector<node> nodes;
    int posX{1}, posY{1};

    while (std::getline(input, line)){
        std::vector<char> temp{};
        
        posX = 1;

        // Adding buffer around the puzzle input
        temp.push_back('-');

        for (auto a: line){
            
            if (a == '#'){
                node tempNode;
                tempNode.x = posX;
                tempNode.y = posY;
                nodes.push_back(tempNode);
            }

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

    /*
    for (auto node: nodes){
        std::cout << "node     node.x = " << node.x << "   -   node.y = " << node.y << std::endl;
    }
    */

    // Adding buffer around the entire puzzle input
    std::vector<char> temp(map[0].size(), '-');
    map.push_back(temp);
    map.insert(map.begin(), temp);

    for(auto y: map){
        std::cout << "\n";
        for(auto x:y){
            std::cout << x;
        }
    }

    /*
    std::cout << "---Original nodes---" << std::endl;
    for (auto node : nodes){
        std::cout << "node.x = " << node.x << "   -   node.y = " << node.y << "\n\n" << std::endl;
    }
    */

    sum1 = part1(map, startPosition);

    int X{}, Y{};

    for (auto& y : map){
        if( y[3] == '-')
            continue;
        X=0;
        Y++;
        for (auto& x : y){
            //std::cout << "x: " << X << " y: " << Y << " - char: " << x << std::endl; 
            X++; 
            if (x == '.'){

                std::vector<node> tempNodes = nodes;
                node tempNode;
                tempNode.x = X;
                tempNode.y = Y;
                tempNodes.push_back(tempNode);

                x = '#';

                if (part2(map, startPosition, tempNodes)){
                    sum2++;
                }

                x = '.';

                std::cout << sum2 << std::endl;
            }
        }
        std::cout << "row: " << Y << " sum: " << sum2 << std::endl;        
    }

    std::cout << "part 1: " << sum1 << std::endl;
    std::cout << "part 2: " << sum2 << std::endl;
}