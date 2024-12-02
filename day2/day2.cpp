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
        //std::cout << "last " << last << " - current: " << current << std::endl;

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
            //std::cout << "---" << last << " and " << current << " --- false" << std::endl;
            return false;
        }

        last = current; 
    }
    return true;
}

void part2(){
    return;
}

void day2() {
    std::ifstream input("../day2/inputDay2.txt");

    if (!input) {
        std::cerr << "Failed to open file." << std::endl;
        return ;
    }

    std::string line;
    int sum{};

    while (std::getline(input, line)) {
        //std::cout << "\n Line: " << line << std::endl;
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
        
        if(part1(row))
            sum++;
    }

    std::cout << "Part 1: " << sum << std::endl;
    return;
}