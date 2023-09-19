# Add test executable
add_executable(protocol_test
    protocol_test.cpp
)

# Link libraries
target_link_libraries(protocol_test PRIVATE
    gtest
    gtest_main
)

# Include directories for Google Test headers
target_include_directories(protocol_test PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/googletest/googletest/include
    ${CMAKE_SOURCE_DIR}/include
)

# Add tests to CTest
add_test(NAME Protocol_Test COMMAND protocol_test)