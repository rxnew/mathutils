cmake_minimum_required(VERSION 2.8)

add_executable(vector-test
  vector_test.cpp
  hyperrectangle_test.cpp
  )

target_link_libraries(vector-test
  gtest
  gtest_main
  pthread
  )

add_test(
  NAME vector
  COMMAND $<TARGET_FILE:vector-test>
  )

# run with: ctest -L lib
set_property(
  TEST vector
  PROPERTY LABELS lib vector
  )
