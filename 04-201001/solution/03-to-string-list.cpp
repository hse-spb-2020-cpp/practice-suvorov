#include <cassert>
#include <list>
#include <string>
#include <sstream>

using Container = std::list<int>;
using ContainerIterator = Container::iterator;

auto to_string(ContainerIterator begin, ContainerIterator end) {
    std::stringstream s;
    s << "{";
    for (auto it = begin; it != end; ++it) {
        if (it != begin) {
            s << ", ";
        }
        s << *it;
    }
    s << "}";
    return s.str();
}

int main() {
    Container data = {1, 2, 3, 4, 5};

    assert(to_string(data.begin(), data.end()) == "{1, 2, 3, 4, 5}");
    assert(to_string(std::next(data.begin(), 2), --data.end()) == "{3, 4}");
    assert(to_string(data.end(), data.end()) == "{}");
    assert(to_string(std::next(data.begin(), 2), std::next(data.begin(), 2)) == "{}");
}
