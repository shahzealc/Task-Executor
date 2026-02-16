cmake_minimum_required(VERSION 3.15)
project(TaskExecutor)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Set output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/inc)

# Source files
set(SOURCES
    src/ComputationTask.cpp
    src/SleepTask.cpp
    src/FileWriteTask.cpp
    src/DatabaseQueryTask.cpp
    src/TaskManager.cpp
    main.cpp
)

# Create executable
add_executable(task-executor ${SOURCES})

# Link threading library (required for std::async, std::thread, std::mutex)
find_package(Threads REQUIRED)
target_link_libraries(task-executor PRIVATE Threads::Threads)

# Compiler-specific flags for better warnings
if(MSVC)
    target_compile_options(task-executor PRIVATE /W4)
else()
    target_compile_options(task-executor PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Print build information
message(STATUS "Building TaskExecutor project")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Source files: ${SOURCES}")
