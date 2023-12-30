SET(TEST_FILE test.cpp)
add_executable(TEST_STRING ${TEST_FILE})
target_link_libraries(TEST_STRING gtest_main)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/String)

enable_testing()