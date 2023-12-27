SET(TEST_FILE test.cpp)
add_executable(TEST_LIST ${TEST_FILE})
target_link_libraries(TEST_LIST gtest_main)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/HashMap)

enable_testing()