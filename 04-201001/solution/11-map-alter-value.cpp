#include <cassert>
#include <map>

using Container = std::map<int, double>;
using ContainerIterator = Container::iterator;

void increase_keys(ContainerIterator begin, ContainerIterator end) {
    for (auto it = begin; it != end; ++it) {
        it->second += 10;
    }
}

int main() {
    Container data = {
        {2, 2.5},
        {1, 1.5},
        {3, 3.5}
    };

    increase_keys(std::next(data.begin()), data.end());
    assert((data == Container{
        {1, 1.5},
        {2, 12.5},
        {3, 13.5}
    }));
}
