#include <cassert>
#include <list>
#include <string>
#include <sstream>

using Container = std::list<int>;
using ContainerIterator = Container::iterator;

// TODO: copy to_string from 01-to-string.cpp verbatim.

int main() {
    Container data = {1, 2, 3, 4, 5};

    assert(to_string(data.begin(), data.end()) == "{1, 2, 3, 4, 5}");
    assert(to_string(TODO, TODO) == "{3, 4}");
    assert(to_string(data.end(), data.end()) == "{}");
    assert(to_string(TODO, TODO) == "{}");
}
