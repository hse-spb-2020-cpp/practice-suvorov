#include <cassert>
#include <map>
#include <string>
#include <sstream>

using Container = std::map<int, double>;
using ContainerIterator = Container::iterator;

auto to_string(ContainerIterator begin, ContainerIterator end) {
    std::stringstream s;
    s << "{";
    for (auto it = begin; it != end; ++it) {
        if (it != begin) {
            s << ", ";
        }
        s << it->first << " -> " << it->second;
    }
    s << "}";
    return s.str();
}

int main() {
    Container data = {
        {2, 2.5},
        {1, 1.5},
        {3, 3.5}
    };

    assert(to_string(data.begin(), data.end()) == "{1 -> 1.5, 2 -> 2.5, 3 -> 3.5}");
    assert(to_string(++data.begin(), data.end()) == "{2 -> 2.5, 3 -> 3.5}");
    assert(to_string(std::next(data.begin(), 2), --data.end()) == "{}");
}
