SET(TEST_FILE test.cpp)
add_executable(TEST_SEARCH ${TEST_FILE})
target_link_libraries(TEST_SEARCH gtest_main)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/Search)

enable_testing()