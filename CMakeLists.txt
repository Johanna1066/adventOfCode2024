cmake_minimum_required(VERSION 3.10)

# Set the project name
project(AoC)

# Add include directories
include_directories(include)

# Add the executable
add_executable(AoC main.cpp)

# Add the daily directories
# add_subdirectory(day1)
# add_subdirectory(day2)
# add_subdirectory(day3)
# add_subdirectory(day4)
# add_subdirectory(day5)
# add_subdirectory(day6)
add_subdirectory(day7)
# add_subdirectory(day9)

# Link the daily libraries to the main executable
# target_link_libraries(AoC PRIVATE day1)
# target_link_libraries(AoC PRIVATE day2)
# target_link_libraries(AoC PRIVATE day3)
# target_link_libraries(AoC PRIVATE day4)
# target_link_libraries(AoC PRIVATE day5)
# target_link_libraries(AoC PRIVATE day6)
target_link_libraries(AoC PRIVATE day7)
# target_link_libraries(AoC PRIVATE day9)

# Add the functions.cpp file to the build process
add_library(functions functions.cpp)
target_link_libraries(AoC PRIVATE functions)