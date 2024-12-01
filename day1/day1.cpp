#include "day1.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>


void part1(std::vector<int> left, std::vector<int> right){
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    int sum{};
    for (int i =0; i < left.size(); i++){
        int diff = abs(left[i] - right[i]);
        sum += diff;
    }

    std::cout << "Answer part 1: " << sum << std::endl;
    return;
}

void part2(std::vector<int> left, std::vector<int> right){
    int sum{};

    for (int num:left){
        int occurences = std::count(right.begin(),right.end(),num);
        sum += (num*occurences);
    }
    std::cout << "Answer part 2: " << sum << std::endl;
}

void day1() {
    std::ifstream input("../day1/inputDay1.txt");

    if (!input) {
        std::cerr << "Failed to open file." << std::endl;
        return ;
    }

        std::string line;
        std::vector<int> left;
        std::vector<int> right;

        while (std::getline(input, line)) {
            std::stringstream ss;
            ss << line;

            bool leftFilled{true};

            std::string temp;
            int found;

            while (!ss.eof()) {
    
                ss >> temp;
    
                if (std::stringstream(temp) >> found){
                    if(leftFilled) {
                        left.push_back(found);
                        leftFilled = false;
                    } else {
                        right.push_back(found);
                    }
                }
                temp = "";
        }
    }

    part1(left, right);
    part2(left,right);
    return;
}