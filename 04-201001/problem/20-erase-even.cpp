#include <cassert>
#include <iterator>
#include <set>

using Container = std::set<int>;

int main() {
    Container s = {1, 2, 3, 4, 5, 6, 7, 8};

    // Do not use std::remove_if here, please, implement it yourself.
    // TODO

    assert((s == Container{1, 3, 5, 7}));
    return 0;
}
