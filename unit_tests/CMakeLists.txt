file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(plane_tests ${CMAKE_SOURCE_DIR}/unit_tests/test_plane.cpp ${SRC_FILES})
target_link_libraries(plane_tests gtest gmock pthread)
target_include_directories(plane_tests PUBLIC ${CMAKE_SOURCE_DIR}/include)
add_test(NAME PLANE_TESTS COMMAND plane_tests)

add_executable(point_tests ${CMAKE_SOURCE_DIR}/unit_tests/test_point.cpp ${SRC_FILES})
target_link_libraries(point_tests gtest gmock pthread)
target_include_directories(point_tests PUBLIC ${CMAKE_SOURCE_DIR}/include)
add_test(NAME POINT_TESTS COMMAND point_tests)

add_executable(triangle_tests ${CMAKE_SOURCE_DIR}/unit_tests/test_triangle.cpp ${SRC_FILES})
target_link_libraries(triangle_tests gtest gmock pthread)
target_include_directories(triangle_tests PUBLIC ${CMAKE_SOURCE_DIR}/include)
add_test(NAME TRIANGLE_TESTS COMMAND triangle_tests)

add_executable(vector_tests ${CMAKE_SOURCE_DIR}/unit_tests/test_vector.cpp ${SRC_FILES})
target_link_libraries(vector_tests gtest gmock pthread)
target_include_directories(vector_tests PUBLIC ${CMAKE_SOURCE_DIR}/include)
add_test(NAME VECTOR_TESTS COMMAND vector_tests)
