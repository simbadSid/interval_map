#include "../shared_routine.h"


class CorrectnessTest : public Test
{
public:
    TestResult scenario() override
    {
        interval_map<int, char> imap('A'); // Initial value is 'A'

        // Assign intervals
        imap.assign(1, 3, 'B'); // [1, 3) -> 'B'
        imap.assign(3, 5, 'C'); // [3, 5) -> 'C'
        imap.assign(0, 1, 'D'); // [0, 1) -> 'D'

        // Test lookups
        if (imap[-1] != 'A') return TestResult(false, "Lookup for -1 failed.");
        if (imap[0] != 'D') return TestResult(false, "Lookup for 0 failed.");
        if (imap[1] != 'B') return TestResult(false, "Lookup for 1 failed.");
        if (imap[2] != 'B') return TestResult(false, "Lookup for 2 failed.");
        if (imap[3] != 'C') return TestResult(false, "Lookup for 3 failed.");
        if (imap[4] != 'C') return TestResult(false, "Lookup for 4 failed.");
        if (imap[5] != 'A') return TestResult(false, "Lookup for 5 failed.");
        if (imap[6] != 'A') return TestResult(false, "Lookup for 5 failed.");
        if (imap[7] != 'A') return TestResult(false, "Lookup for 5 failed.");

        return TestResult(true, "All correctness tests passed.");
    }
};

// Entry point for the test case
int main()
{
    CorrectnessTest test;
    return test.shared_main();
}
