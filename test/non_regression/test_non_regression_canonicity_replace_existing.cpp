#include "../shared_routine.h"


class CanonicityTest : public Test
{
public:
    TestResult scenario() override
    {
        interval_map<int, char> imap('A');

        // Assign initial intervals
        imap.assign(1, 3, 'B'); // [1, 3) -> 'B'
        imap.assign(3, 5, 'C'); // [3, 5) -> 'C'

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
