#include <cassert>
#include <iterator>
#include <list>

using Container = std::list<int>;
using ContainerIterator = Container::iterator;

int main() {
    Container data = {1, 2, 3, 4, 5};

    auto a = data.begin();
    auto b = a; ++b;
    auto c = b; ++c;
    auto d = c; ++d;
    auto e = d; ++e;
    auto f = e; ++f;

    assert(*a == 1);
    assert(*b == 2);
    assert(*c == 3);
    assert(*d == 4);
    assert(*e == 5);

    assert(std::TODO(a) == b);
    assert(*a == 1);
    assert(*b == 2);

    assert(std::TODO(b) == a);
    assert(*a == 1);
    assert(*b == 2);

    assert(std::TODO(a, TODO) == c);
    assert(*a == 1);
    assert(*c == 3);

    assert(std::TODO(c, TODO) == a);
    assert(*a == 1);
    assert(*c == 3);

    std::TODO(a, 2);
    assert(a == c);
    assert(*a == 3);
    assert(*c == 3);
}
