SET(TEST_FILE test.cpp)
add_executable(TEST_GREEDY ${TEST_FILE})
target_link_libraries(TEST_GREEDY gtest_main)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/Greedy)

enable_testing()