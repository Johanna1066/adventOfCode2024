cmake_minimum_required(VERSION 3.10)

# Set the project name
project(AoC)

# Add the executable
add_executable(AoC main.cpp)

# Add the day1 directory
add_subdirectory(day1)

# Link the day1 library to the main executable
target_link_libraries(AoC PRIVATE day1)
target_link_libraries(AoC PRIVATE day2)