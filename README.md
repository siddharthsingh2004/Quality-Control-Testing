# Quality Control (QC) Testing

## Overview
This project implements a system for validating and analyzing automated Quality Control (QC) test result strings from a manufacturing tracker. The program verifies the correctness of QC test result strings and extracts relevant statistics such as the number of passing tests, defective tests, total tests, and batches.

## Features
- **Validation of QC Test Strings**: Ensures the input follows the correct format.
- **Count of Passed Tests**: Returns the total number of tests that passed.
- **Count of Defective Tests**: Returns the total number of defective tests.
- **Total Number of Tests**: Returns the sum of all tests across batches.
- **Batch Counting**: Identifies and counts the number of batches in the QC string.

## File Structure
- `qctest.cpp`: Contains the implementation of all required functions and a test suite to validate functionality.
- `Project3Specifications.pdf`: Contains the problem description and requirements for the project.

## Functions Implemented
### `bool isValidQC(string results)`
Checks if the given QC test result string is valid according to the specifications.

### `int passQC(string results)`
Returns the total number of passing test results. If the input is invalid, returns -1.

### `int defectQC(string results)`
Returns the total number of defective test results. If the input is invalid, returns -1.

### `int totalQC(string results)`
Returns the total number of QC tests performed. If the input is invalid, returns -1.

### `int batches(string results)`
Returns the total number of batches reported in the string. If the input is invalid, returns -1.

## Compilation and Execution
To compile and execute the program, use the following commands:
```sh
# Compile the program
 g++ -c qctest.cpp
 g++ qctest.o -o qc_tester

# Run the program
 ./qc_tester
```

## Testing
The `main` function in `qctest.cpp` contains a set of assertions to validate the correctness of the functions. The program runs various test cases to ensure proper functionality. If all test cases pass, it outputs:
```sh
All test cases passed!
```

## Example Usage
### Valid Example
```sh
Input: "Q2p1d1Q5p3d2"
Output:
  isValidQC: true
  passQC: 4
  defectQC: 3
  totalQC: 7
  batches: 2
```

### Invalid Example
```sh
Input: "Q1pd1"
Output:
  isValidQC: false
  passQC: -1
  defectQC: -1
  totalQC: -1
  batches: -1
```

## Author
Developed by Siddharth Singh

## License
This project is for educational purposes and follows standard academic integrity policies.



