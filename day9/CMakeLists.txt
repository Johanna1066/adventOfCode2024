# Add the source files for day9
add_library(day9 day9.cpp)

# Include the directory for header files
target_include_directories(day9 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})