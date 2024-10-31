#include "../shared_routine.h"


class CanonicityTest : public Test
{
public:
    TestResult scenario() override
    {
        interval_map<int, char> imap('A');

        // Assign non-overlapping intervals
        imap.assign(1, 2, 'B'); // [1, 2) -> 'B'
        imap.assign(3, 4, 'C'); // [3, 4) -> 'C'

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
