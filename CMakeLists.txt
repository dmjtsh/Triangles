cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(triangles_proj VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(triangles_proj main.cpp ${SRC_FILES})
target_include_directories(triangles_proj PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(program_tests ${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp ${SRC_FILES})
target_link_libraries(program_tests gtest gmock pthread)
target_include_directories(program_tests PUBLIC ${CMAKE_SOURCE_DIR}/include)
add_test(NAME PROGRAM_TESTS COMMAND program_tests)

add_subdirectory(modules_unit_tests)
