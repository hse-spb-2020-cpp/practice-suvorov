#include <cassert>
#include <list>
#include <string>
#include <sstream>

using Container = std::list<int>;
using ContainerIterator = Container::iterator;

// TODO: copy to_string from 01-to-string.cpp verbatim and fix types of its parameters.

int main() {
    Container data_storage = {1, 2, 3, 4, 5};
    const Container &data = data_storage;

    assert(to_string(data.begin(), data.end()) == "{1, 2, 3, 4, 5}");
    assert(to_string(std::next(data.begin(), 2), --data.end()) == "{3, 4}");
    assert(to_string(data.end(), data.end()) == "{}");
    assert(to_string(std::next(data.begin(), 2), std::next(data.begin(), 2)) == "{}");
}
