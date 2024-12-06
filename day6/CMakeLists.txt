# Add the source files for day6
add_library(day6 day6.cpp)

# Include the directory for header files
target_include_directories(day6 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})