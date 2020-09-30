#include <cassert>
#include <vector>

void foo(std::vector<int> &v) {
    // TODO
}

int main() {
    std::vector<int> v = {1, 2, 3, 4};
    int &x = v[0];
    foo(v);
    assert(v.size() >= 1);
    x = 1;  // Should trigger undefined behavior.
}
