SET(TEST_FILE test.cpp)
add_executable(TEST_DOUBLEPOINTER ${TEST_FILE})
target_link_libraries(TEST_DOUBLEPOINTER gtest_main)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/DoublePointer)

enable_testing()