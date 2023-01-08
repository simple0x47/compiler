project(compilerTest)

add_executable(compilerTest example.cc)
target_link_libraries(compilerTest gtest_main)