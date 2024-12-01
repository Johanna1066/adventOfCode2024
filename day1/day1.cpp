#include "day1.h"
#include <fstream>
#include <iostream>
#include <string>

void readFile(std::ifstream &input) {

    std::string s;

    while (std::getline(input, s)) {
        std::cout << s << std::endl;
    }

    return;
}