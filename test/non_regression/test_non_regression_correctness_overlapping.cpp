#include "../shared_routine.h"


class CorrectnessTest : public Test
{
public:
    TestResult scenario() override
    {
        interval_map<int, char> imap('A'); // Initial value is 'A'

        // Assign overlapping intervals
        imap.assign(1, 4, 'B'); // [1, 4) -> 'B'
        imap.assign(2, 5, 'C'); // [2, 5) -> 'C'

        // Test lookups
        if (imap[0] != 'A') return TestResult(false, "Lookup for 0 failed.");
        if (imap[1] != 'B') return TestResult(false, "Lookup for 1 failed.");
        if (imap[2] != 'C') return TestResult(false, "Lookup for 2 failed.");
        if (imap[3] != 'C') return TestResult(false, "Lookup for 3 failed.");
        if (imap[4] != 'C') return TestResult(false, "Lookup for 4 failed.");
        if (imap[5] != 'A') return TestResult(false, "Lookup for 5 failed.");
        if (imap[6] != 'A') return TestResult(false, "Lookup for 5 failed.");

        return TestResult(true, "All correctness tests passed.");
    }
};

// Entry point for the test case
int main()
{
    CorrectnessTest test;
    return test.shared_main();
}
