#include "../shared_routine.h"


class CanonicityTest : public Test
{
public:
    TestResult scenario() override
    {
        interval_map<int, char> imap('A');

        // Assign multiple overlapping intervals
        imap.assign(1, 5, 'B'); // [1, 5) -> 'B'
        imap.assign(2, 3, 'C'); // [2, 3) -> 'C'
        imap.assign(4, 6, 'B'); // [4, 6) -> 'B', should merge to [1, 6) -> 'B'

        // Replace an existing interval
        imap.assign(1, 5, 'D'); // [1, 5) -> 'D', should replace previous intervals

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
