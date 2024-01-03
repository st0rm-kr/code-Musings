SET(TEST_FILE test.cpp)
add_executable(TEST_STACKQUEUE ${TEST_FILE})
target_link_libraries(TEST_STACKQUEUE gtest_main)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/StackQueue)

enable_testing()