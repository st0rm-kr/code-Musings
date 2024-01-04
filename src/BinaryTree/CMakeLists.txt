SET(TEST_FILE test.cpp)
add_executable(TEST_BINARYTREE ${TEST_FILE})
target_link_libraries(TEST_BINARYTREE gtest_main)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/BinaryTree)

enable_testing()