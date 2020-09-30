#include <cassert>
#include <iterator>
#include <set>

using Container = std::set<int>;

int main() {
    Container s = {1, 2, 3, 4, 5, 6, 7, 8};

    // Do not use std::remove_if here, please, implement it yourself.
    for (auto it = s.begin(); it != s.end();) {
        if (*it % 2 == 0) {
            it = s.erase(it);
        } else {
            ++it;
        }
    }

    assert((s == Container{1, 3, 5, 7}));
    return 0;
}
