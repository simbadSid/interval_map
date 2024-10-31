#include "../shared_routine.h"


class TypeRequirementsTest : public Test
{
public:
    TestResult scenario() override
    {
        // Check that K and V can be instantiated correctly
        try
        {
            interval_map<TestResult, char> map('A');
            return TestResult(true, "Type requirements failed.");
        }
        catch (...)
        {
            return TestResult(false, "Type requirements passed.");
        }
    }
};

// Entry point for the test case
int main()
{
    TypeRequirementsTest test;
    return test.shared_main();
}