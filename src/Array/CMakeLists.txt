SET(TEST_FILE test.cpp)
add_executable(TEST_ARRAY ${TEST_FILE})
target_link_libraries(TEST_ARRAY gtest_main)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/Array)

enable_testing()