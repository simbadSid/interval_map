#include "../shared_routine.h"


class CanonicityTest : public Test
{
public:
    TestResult scenario() override
    {
        interval_map<int, char> imap('A');

        // Assign overlapping intervals
        imap.assign(1, 4, 'B'); // [1, 4) -> 'B'
        imap.assign(2, 5, 'B'); // [2, 5) -> 'B', should merge with the previous

        // Check for no consecutive duplicates in m_map
        if (imap.consecutive_duplicates())
        {
            return TestResult(false, "Consecutive duplicates found in map.");
        }
        else
        {
            return TestResult(true, "Canonicity test passed.");
        }
    }
};

// Entry point for the test case
int main()
{
    CanonicityTest test;
    return test.shared_main();
}
