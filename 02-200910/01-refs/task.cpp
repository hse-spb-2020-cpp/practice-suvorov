#include <assert.h>
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    // TASK 1
    assert(min(10, 20) == 10);
    assert(min(20, 10) == 10);
    assert(min(20, 30) == 20);

    // TASK 2
    {
        int a = 10, b = 20;
        swap(a, b);
        assert(a == 20);
        assert(b == 10);
    }

    // TASK 3
    // `const vector<int>&` can be bound to a temporary value.
    // Extra watch: 'Rvalue lifetime disaster' by Arno Schoedl.
    printAll(std::vector{1, 2, 3});  // Should print "1 2 3\n"

    // TASK 4
    // assert({1, 2, 3}) gets parsed like assert(/* first argument */ {1 , /* second argument */ 2 , /* third argument */ 3})
    // because macros do not know about {}, like they do about (). Hence, extra () is needed for correct parsing.
    assert((sorted(std::vector{30, 10, 20}) == std::vector{10, 20, 30}));  // Use std::sort
    {
        std::vector<int> v{30, 10, 20};
        assert((sorted(v) == std::vector{10, 20, 30}));
        assert((v == std::vector{30, 10, 20}));
    }
}
  