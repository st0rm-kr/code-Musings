SET(TEST_FILE test.cpp)
add_executable(TEST_HASHMAP ${TEST_FILE})
target_link_libraries(TEST_HASHMAP gtest_main)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/HashMap)

enable_testing()