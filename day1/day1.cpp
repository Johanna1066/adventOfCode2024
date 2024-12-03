// day1.cpp
// https://adventofcode.com/2024/day/1

#include "day1.h"
#include "../functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

void part1(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> sortedLeft = left;
    std::vector<int> sortedRight = right;
    std::sort(sortedLeft.begin(), sortedLeft.end());
    std::sort(sortedRight.begin(), sortedRight.end());

    int sum = 0;
    for (size_t i = 0; i < sortedLeft.size(); ++i) {
        int diff = abs(sortedLeft[i] - sortedRight[i]);
        sum += diff;
    }

    std::cout << "Answer part 1: " << sum << std::endl;
}

void part2(const std::vector<int>& left, const std::vector<int>& right) {
    int sum = 0;

    for (int num : left) {
        int occurrences = std::count(right.begin(), right.end(), num);
        sum += (num * occurrences);
    }
    std::cout << "Answer part 2: " << sum << std::endl;
}

void day1() {
    std::string fileURL = "../day1/inputDay1.txt";
    std::ifstream input = readFile(fileURL);

    std::string line;
    std::vector<int> left;
    std::vector<int> right;

    while (std::getline(input, line)) {
        std::stringstream ss(line);
        bool leftFilled = true;
        int found;

        while (ss >> found) {
            if (leftFilled) {
                left.push_back(found);
                leftFilled = false;
            } else {
                right.push_back(found);
                leftFilled = true;
            }
        }
    }

    part1(left, right);
    part2(left, right);

    input.close();
}