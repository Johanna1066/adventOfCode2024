// day4.cpp
// https://adventofcode.com/2024/day/4

#include "day4.h"
#include "../functions.h"
#include <iostream>
#include <vector>


// Declarations 
// Part 1
int searchLeftRight(std::vector<std::vector<char>>&, int&, int&);
int searchUpDown(std::vector<std::vector<char>>&, int&, int&);
int searchDiagRight(std::vector<std::vector<char>>&, int&, int&);
int searchDiagLeft(std::vector<std::vector<char>>&, int&, int&);
//Part2
int searchAround(std::vector<std::vector<char>>&, int&, int&);


int part1(std::vector<std::vector<char>>& lines) {

    int sum{};

    for (int y=0; y < lines.size(); y++ ){

        for (int x=0; x < lines[0].size(); x++){
            if (lines[y][x] == 'X'){
                    sum += searchUpDown(lines, x, y);
                    sum += searchLeftRight(lines, x, y);
                    sum += searchDiagLeft(lines, x, y);
                    sum += searchDiagRight(lines, x, y);
            }
        }
    }
    return sum;
}

int part2(std::vector<std::vector<char>> &lines){

    int sum{};

    for (int y = 0; y < lines.size(); y++){

        for (int x = 0; x < lines[0].size(); x++){

            if (lines[y][x] == 'A'){
                sum += searchAround(lines, x, y);
            }
        }
    }
    return sum;
}

void day4()
{
    std::string fileURL = "../day4/inputDay4.txt";
    std::ifstream input = readFile(fileURL);

    std::string line;
    std::vector<std::vector<char>> lines;
    int sum1{}, sum2{};

    while (std::getline(input, line)){
        std::vector<char> temp;

        // Adding buffer around the puzzle input
        // to fix out of range issues when searching
        temp.push_back('.');
        temp.push_back('.');
        temp.push_back('.');

        for (auto a: line){
            temp.push_back(a);
        }

        // Adding buffer around the puzzle input
        // to fix out of range issues when searching
        temp.push_back('.');
        temp.push_back('.');
        temp.push_back('.');

        lines.push_back(temp);
    }

    // Adding buffer around the puzzle input
    // to fix out of range issues when searching
    {
        std::vector<char> temp;

            for(auto c:lines[0]){
                temp.push_back('.');
            }

        lines.push_back(temp);
        lines.push_back(temp);
        lines.push_back(temp);

        lines.insert(lines.begin(), temp);
        lines.insert(lines.begin(), temp);
        lines.insert(lines.begin(), temp);
    }
    
    input.close();

    sum1 = part1(lines);
    sum2 = part2(lines);

    std::cout << "part 1: " << sum1 << std::endl;
    std::cout << "part 2: " << sum2 << std::endl;
}

int searchLeftRight(std::vector<std::vector<char>>& lines, int& x, int& y){

    int sum{};

    if (lines[y][x-1] == 'M' && lines[y][x-2] == 'A' && lines[y][x-3] == 'S')
        sum++;
      
    if (lines[y][x+1] == 'M' && lines[y][x+2] == 'A' && lines[y][x+3] == 'S')
        sum++;

    return sum;
}

int searchUpDown(std::vector<std::vector<char>>& lines, int& x, int& y){

    int sum{};

    if (lines[y-1][x] == 'M' && lines[y-2][x] == 'A' && lines[y-3][x] == 'S')
        sum++;

    if (lines[y+1][x] == 'M' && lines[y+2][x] == 'A' && lines[y+3][x] == 'S')
        sum++;

    return sum;
}

int searchDiagRight(std::vector<std::vector<char>>& lines, int &x, int& y){
    int sum{};
    if (lines[y-1][x-1] == 'M' && lines[y-2][x-2] == 'A' && lines[y-3][x-3] == 'S')
        sum++;

    if (lines[y+1][x+1] == 'M' && lines[y+2][x+2] == 'A' && lines[y+3][x+3] == 'S')
        sum++;

    return sum;
}

int searchDiagLeft(std::vector<std::vector<char>>& lines, int& x, int& y){
    int sum{};
    if (lines[y+1][x-1] == 'M' && lines[y+2][x-2] == 'A' && lines[y+3][x-3] == 'S')
        sum++;

    if (lines[y-1][x+1] == 'M' && lines[y-2][x+2] == 'A' && lines[y-3][x+3] == 'S')
        sum++;

    return sum;
}

int searchAround(std::vector<std::vector<char>>& lines, int& x, int& y){

    int sum{};

    if ((lines[y - 1][x - 1] == 'M') && (lines[y - 1][x + 1] == 'S') && (lines[y + 1][x - 1] == 'M') && (lines[y + 1][x + 1] == 'S')){
        sum++;
    }
    if ((lines[y - 1][x - 1] == 'M') && (lines[y - 1][x + 1] == 'M') && (lines[y + 1][x - 1] == 'S') && (lines[y + 1][x + 1] == 'S')){
        sum++;
    }
    if ((lines[y - 1][x - 1] == 'S') && (lines[y - 1][x + 1] == 'S') && (lines[y + 1][x - 1] == 'M') && (lines[y + 1][x + 1] == 'M')){
        sum++;
    }
    if ((lines[y - 1][x - 1] == 'S') && (lines[y - 1][x + 1] == 'M') && (lines[y + 1][x - 1] == 'S') && (lines[y + 1][x + 1] == 'M')){
        sum++;
    }

    return sum;
}