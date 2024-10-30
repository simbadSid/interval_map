# CMake generated Testfile for 
# Source directory: /Users/riyane/Desktop/workspace/think-cell-assignment
# Build directory: /Users/riyane/Desktop/workspace/think-cell-assignment/bin
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[test_non_regression_1]=] "/Users/riyane/Desktop/workspace/think-cell-assignment/bin/test_non_regression_1")
set_tests_properties([=[test_non_regression_1]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/riyane/Desktop/workspace/think-cell-assignment/CMakeLists.txt;169;add_test;/Users/riyane/Desktop/workspace/think-cell-assignment/CMakeLists.txt;0;")
add_test([=[test_valgrind_1]=] "valgrind" "--leak-check=full" "--error-exitcode=1" "test_valgrind_1")
set_tests_properties([=[test_valgrind_1]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/riyane/Desktop/workspace/think-cell-assignment/CMakeLists.txt;167;add_test;/Users/riyane/Desktop/workspace/think-cell-assignment/CMakeLists.txt;0;")
