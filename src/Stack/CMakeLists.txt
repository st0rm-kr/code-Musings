SET(TEST_FILE test.cpp)
add_executable(TEST_STACK ${TEST_FILE})
target_link_libraries(TEST_STACK gtest_main)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/Stack)

enable_testing()