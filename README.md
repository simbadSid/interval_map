# Interval Map Project

## Project Overview

The `Interval Map` project implements a data structure that associates keys of type `K` with values of type `V` over specified intervals. This data structure is designed to efficiently manage mappings of consecutive keys to their corresponding values, allowing for easy assignment and retrieval of values over specified intervals.

## Key and Value Requirements

### Key Type (`K`)
- **Copy and Move**: Must support copy construction, move construction, copy assignment, and move assignment.
- **Comparison**: Must be less-than comparable via the operator `<`.
- **No Other Operations**: Must not implement any other operations, particularly no equality comparison or arithmetic operators.

### Value Type (`V`)
- **Copy and Move**: Must support copy construction, move construction, copy assignment, and move assignment.
- **Equality Comparison**: Must be equality-comparable via the operator `==`.
- **No Other Operations**: Must not implement any other operations.

## Solution Description

The primary class in this project is `interval_map`, which provides functionalities to assign values to specific intervals and retrieve values associated with individual keys. The main features of the implementation include:

- **Assignment of Intervals**: The `assign` method allows users to assign a value `val` to an interval `[keyBegin, keyEnd)`, where `keyBegin` is included, and `keyEnd` is excluded. The method ensures that overlapping intervals are merged and that no duplicate entries are created.

- **Lookup of Values**: The `operator[]` is overloaded to provide easy access to the value associated with a specific key. If the key falls outside any defined intervals, it returns a default value.

- **Canonical Representation**: The internal representation of the mapping ensures that consecutive entries with the same value are merged, maintaining a canonical form.

## Test Scenarios

The project includes a suite of test scenarios designed to validate the functionality of the `interval_map` implementation. The tests cover various aspects, ensuring both correctness and canonicity:

### 1. Correctness Tests
- **Basic Assignment**: Verifies that simple assignments are stored and retrieved correctly.
- **Overlapping Intervals**: Checks if overlapping intervals merge correctly.
- **Adjacent Intervals**: Ensures that adjacent intervals are handled correctly.
- **Replacing Intervals**: Tests that assigning a new value to an existing interval replaces it appropriately.

### 2. Canonicity Tests
- **Merging Overlapping Intervals**: Validates that overlapping intervals with the same value are merged.
- **Adjacent Intervals**: Confirms that adjacent intervals are stored correctly without duplicates.
- **Non-Overlapping Intervals**: Ensures that non-overlapping intervals remain separate and do not interfere with each other.
- **Complex Merging**: Tests multiple overlapping and adjacent intervals to ensure correct merging behavior.

## How to Build and Test

### Prerequisites

Make sure you have CMake installed along with a C++ compiler (e.g., g++, clang++).

### Building the Project

1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd interval_map
2. Navigate to the bin directory (which already exists):
   ```bash
   cd bin
3. Run CMake to configure the project:
   ```bash
   cmake ..
4. Compile the project:
  ```bash
    make
