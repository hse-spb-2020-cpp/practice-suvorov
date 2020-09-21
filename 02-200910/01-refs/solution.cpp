#include <assert.h>
#include <algorithm>
#include <iostream>
#include <vector>

auto min(int a, int b) {
    if (a < b) {  // Use {}
        return a;  // Don't use ?:, it plays badly with type deduction
    } else {
        return b;
    }
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    // a ^= b ^= a ^= b;  // DON'T
    // a ^= b; b ^= a; a ^= b; // DON'T
}

void printAll(const std::vector<int> &vec) {
#if 0
    // Weird edge case which was not in the original problem.
    if (vec.empty()) {
        std::cout << "\n";
        return; // Early return, not deep nested 'else'
    }
    for (std::size_t i = 0; i + 1 < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << vec[vec.size() - 1] << "\n";
#else
    // Correct solution.
    bool firstItem = true;
    // See 'Type Deduction And Why You Care' by Scott Meyers to
    // understand why `auto& item` also works: `auto` gets deduced to `const int`.
    for (const auto &item : vec) {
        if (!firstItem) {
            std::cout << ' ';
        }
        firstItem = false;
        std::cout << item;
    }
    std::cout << '\n';
#endif
}

auto sorted(std::vector<int> v) {  // We need a copy, it's better to create it in a parameter so it works better if a temporary is passed into `sorted`.
   std::sort(v.begin(), v.end());
   return v;
}

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
  