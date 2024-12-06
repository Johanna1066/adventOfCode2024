# Add the source files for day7
add_library(day7 day7.cpp)

# Include the directory for header files
target_include_directories(day7 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})