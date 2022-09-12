cmake_minimum_required(VERSION 3.18)
project(example_project LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17) # for std::filesystem

if (BUILD_TESTS) 
  enable_testing()
  add_executable(check_file_size test.cpp)

  include(ExternalData)
  set(ExternalData_URL_TEMPLATES "https://raw.githubusercontent.com/samuelpmish/ExternalData/main/%(algo)/%(hash)")
  ExternalData_Add_Test(MY_DATA 
    NAME check_file_size_is_64KB 
    COMMAND check_file_size DATA{data_file.bin})
  ExternalData_Add_Target(MY_DATA)
endif()
