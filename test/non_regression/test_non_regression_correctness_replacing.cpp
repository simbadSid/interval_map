#include "../shared_routine.h"


class CorrectnessTest : public Test
{
public:
    TestResult scenario() override
    {
        interval_map<int, char> imap('A'); // Initial value is 'A'

        // Assign initial intervals
        imap.assign(1, 3, 'B'); // [1, 3) -> 'B'
        imap.assign(3, 5, 'C'); // [3, 5) -> 'C'

        // Replace an existing interval
        imap.assign(1, 5, 'D'); // [1, 5) -> 'D', should replace previous intervals

        // Test lookups
        if (imap[0] != 'A') return TestResult(false, "Lookup for 0 failed.");
        if (imap[1] != 'D') return TestResult(false, "Lookup for 1 failed.");
        if (imap[2] != 'D') return TestResult(false, "Lookup for 2 failed.");
        if (imap[3] != 'D') return TestResult(false, "Lookup for 3 failed.");
        if (imap[4] != 'D') return TestResult(false, "Lookup for 4 failed.");
        if (imap[5] != 'A') return TestResult(false, "Lookup for 5 failed.");

        return TestResult(true, "All correctness tests passed.");
    }
};

// Entry point for the test case
int main()
{
    CorrectnessTest test;
    return test.shared_main();
}
