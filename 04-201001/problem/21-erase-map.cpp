#include <cassert>
#include <iterator>
#include <map>

using Container = std::map<int, double>;

int main() {
    Container s = {
        {1, 1.5},
        {2, 2.5},
        {3, 3.5}
    };
    double &x = std::next(s.begin(), 0)->second;
    double &y = std::next(s.begin(), 1)->second;
    double &z = std::next(s.begin(), 2)->second;
    assert(x == 1.5);
    assert(y == 2.5);
    assert(z == 3.5);

    // Do not use std::remove_if here, please, implement it yourself.
    // TODO

    assert((s == Container{
        {1, 1.5},
        {3, 3.5}
    }));
    assert(x == 1.5);
    // assert(y == 2.5);  // UB
    assert(z == 3.5);
    x += 10;
    z += 10;
    assert((s == Container{
        {1, 11.5},
        {3, 13.5}
    }));
    return 0;
}
