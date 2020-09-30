#include <cassert>
#include <map>
#include <utility>

using Container = std::map<int, double>;
using ContainerIterator = Container::iterator;

int main() {
    Container data = {
        {2, 2.5},
        {1, 1.5},
        {3, 3.5}
    };

    std::pair<const int, double> &it = *data.begin();  // Do not use auto.
    assert(it.first == 1);
    assert(it.second == 1.5);

    it.second += 10;

    assert((data == Container{
        {1, 11.5},
        {2, 2.5},
        {3, 3.5}
    }));
}
