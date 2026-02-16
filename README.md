# Task Executor

A modular C++ task execution framework that supports asynchronous task management with thread-safe operations.

## Features

- **Modular Design**: Each class is separated into header and implementation files
- **Task Interface**: Abstract `ITask` base class for implementing custom tasks
- **Asynchronous Execution**: Tasks execute concurrently using `std::async`
- **Thread-Safe Operations**: Built-in mutex protection for logging and result storage
- **Result Variant**: Support for multiple result types (int, string, double)
- **Error Handling**: Exception handling with detailed error logging

## Available Tasks

### ComputationTask
Performs simple arithmetic addition of two numbers.

### SleepTask
Simulates a delayed operation by sleeping for specified seconds.

### FileWriteTask
Writes content to a file on disk.

### DatabaseQueryTask
Simulates a database query execution with record count.

## Compilation

### Using G++
```bash
g++ -std=c++17 main.cpp ComputationTask.cpp SleepTask.cpp FileWriteTask.cpp DatabaseQueryTask.cpp TaskManager.cpp -o task-executor
```

### Using CMake
```bash
cmake -B build
cd build
make
```

## Requirements

- C++17 or later
- Standard library with `<variant>`, `<future>`, `<mutex>` support

## Architecture

- **TaskManager**: Orchestrates task execution using async operations
- **Logger**: Provides thread-safe console logging
- **ITask**: Contract for all task implementations
- **TaskResult**: Type-safe result storage using std::variant

## Thread Safety

- Logger uses mutex for thread-safe output
- TaskManager protects result map with mutex during concurrent execution
- Each task executes on its own thread via std::async

## Error Handling

All exceptions are caught during task execution and logged with details including the task name and error message.
