#include <iostream>
#include <fstream>
#include "day1/day1.h"

int main() {
    std::cout << "Opening file..." << std::endl;
    std::ifstream input("../testInputDay1.txt");

    if (!input) {
        std::cerr << "Failed to open file." << std::endl;
        return 0;
    }

    readFile(input);

    std::cout << "Finished reading file." << std::endl;
    return 0;
}