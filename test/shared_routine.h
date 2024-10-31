#ifndef TEST_SHARED_ROUTINE_H
#define TEST_SHARED_ROUTINE_H

#include <iostream>
#include <string>

#include "interval_map.h"


class TestResult
{
public:
    bool        success;
    std::string message;

    TestResult(bool success, const std::string& message): success(success), message(message)
    {}
};


class Test
{
public:
    // Method to be overridden by derived classes
    virtual TestResult scenario() = 0;

    // Method to run the test and report results
    int shared_main()
    {
        std::cout << "Begin Test: \"" << __FILE__ << "\"" << std::endl;

        // Run the scenario and get the result
        TestResult result = this->scenario();

        if (result.success)
        {
            std::cout << "Test \"" << __FILE__ << "\" succeeded: " << result.message << std::endl;
            return 0;
        }
        else
        {
            std::cout << "Test \"" << __FILE__ << "\" failed: " << result.message << std::endl;
            return -1;
        }
    }
};

#endif