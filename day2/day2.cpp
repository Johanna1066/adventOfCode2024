// day2.cpp
// https://adventofcode.com/2024/day/2

#include "day2.h"
#include "../functions.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

bool part1(const std::vector<int>& row) {
    int current{0}, last{0};
    bool first{true};
    bool increasing{true};

    // Check if the current row is increasing or decreasing
    if (row[0] > row[1])
        increasing = false;

    for (auto a : row) {
        if (first) {
            first = false;
            last = a;
            continue;
        }

        current = a;

        if (increasing) {
            if (current <= last)
                return false;
        } else {
            if (current >= last)
                return false;
        }

        if (abs(current - last) > 3) {
            return false;
        }

        last = current;
    }
    return true;
}

// Function to check if a row is valid according to part2's rules
bool part2(std::vector<int> row) {
    for (int i = 0; i < row.size(); i++) {
        std::vector<int> temp = row;
        temp.erase(temp.begin() + i);
        if (part1(temp)) {
            return true;
        }
    }
    return false;
}

// Main function for day2
void day2() {
    std::string fileURL = "../day2/inputDay2.txt";
    std::ifstream input = readFile(fileURL);

    std::string line;
    int sum1{}, sum2{};

    while (std::getline(input, line)) {
        std::vector<int> row{};
        std::stringstream ss(line);
        int value;
        while (ss >> value) {
            row.push_back(value);
        }

        if (part1(row)) {
            sum1++;
        }
        if (part2(row)) {
            sum2++;
        }
    }

    std::cout << "Sum1: " << sum1 << std::endl;
    std::cout << "Sum2: " << sum2 << std::endl;
}