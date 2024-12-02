#include "day2.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

bool part1(std::vector<int> row){
    int current{0}, last{0};
    bool first{true};
    bool increasing{true};
    
    //Check of the current row is increasing or decreasing
    if(row[0] > row[1])
        increasing = false;

    for(auto a : row){

        if(first)
        {
            first = false;
            last = a;
            continue;
        }

        current = a;

        if(increasing){
            if(current <= last)
                return false;
        } else{
            if(current >= last)
                return false;
        }

        if(abs(current-last) > 3 )
        {
            return false;
        }

        last = current; 
    }
    return true;
}

bool part2(std::vector<int> row){
    for (int i = 0; i < row.size(); i++){
        std::vector<int> temp = row; 

        temp.erase(temp.begin() + i);

        if(part1(temp)){
            return true;
        }
    }
    return false;
}

void day2() {
    std::ifstream input("../day2/inputDay2.txt");

    if (!input) {
        std::cerr << "Failed to open file." << std::endl;
        return ;
    }

    std::string line;
    int sum1{}, sum2{};

    while (std::getline(input, line)) {
        std::vector<int> row{};
        std::stringstream ss;
        std::string temp;
        int found;

        ss << line;

        while (!ss.eof()) {
    
            ss >> temp;
    
            if (std::stringstream(temp) >> found){
                row.push_back(found);
            }
            temp = "";
        }
        
        if(part1(row)){
            sum1++;
            sum2++;
        }
        else if (part2(row)){
            sum2++;
        }
    }

    std::cout << "Part 1: " << sum1 << std::endl;
    std::cout << "Part 2: " << sum2 << std::endl;
    return;
}