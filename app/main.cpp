#include <iostream>
#include "tools.h"

#include "interval_map.h"


int main() {
    log("Begin RUN!\n");

    interval_map<int, char> imap('A');

    // Assign intervals
    imap.assign(1, 3, 'B'); // [1, 3) -> 'B'
    imap.assign(3, 5, 'B'); // [3, 5) -> 'B'
    imap.assign(5, 7, 'C'); // [5, 7) -> 'C'


    log("End RUN!\n");

    return 0;
}
