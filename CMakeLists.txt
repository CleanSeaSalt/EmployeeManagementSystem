cmake_minimum_required(VERSION 3.24)
project(EmployeeManagementSystem)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib")


set(CMAKE_CXX_STANDARD 17)

add_executable(EmployeeManagementSystem main.cpp WorkerManager.cpp WorkerManager.h worker.h manager.cpp manager.h employee.cpp employee.h boss.cpp boss.h)


