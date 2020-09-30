#include <cassert>
#include <map>
#include <sstream>

using Container = std::map<int, double>;
using ContainerIterator = Container::iterator;

int main() {
    Container data = {
        {2, 2.5},
        {1, 1.5},
        {3, 3.5}
    };

    std::stringstream s;
    for (auto &[key, value] : data) {  // Hint: use structured binding.
        s << key << " -> " << value << "\n";
        value += 10;
    }
    assert(s.str() == "1 -> 1.5\n2 -> 2.5\n3 -> 3.5\n");

    assert((data == Container{
        {1, 11.5},
        {2, 12.5},
        {3, 13.5}
    }));
}
