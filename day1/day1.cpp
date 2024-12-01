#include "day1.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void day1() {

    std::cout << "Opening file..." << std::endl;
    std::ifstream input("../day1/testInputDay1.txt");

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
    
                /* Checking the given word is integer or not */
                if (std::stringstream(temp) >> found){
                    if(leftFilled) {
                        left.push_back(found);
                        leftFilled = false;
                    } else {
                        right.push_back(found);
                    }
                }
    
                /* To save from space at the end of string */
                temp = "";
        }
    }
    std::cout << "Finished reading file." << std::endl;
    return;
}