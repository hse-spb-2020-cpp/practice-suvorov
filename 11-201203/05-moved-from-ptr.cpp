#include <cassert>
#include <string>
#include <iostream>
#include <memory>
#include <utility>

int main() {
    std::shared_ptr<int> a(new int(10));
    std::shared_ptr<int> b(std::move(a));
    // moved-from состояние у shared_ptr гарантированно пустое.
    std::cout << "a=" << a.get() << "\n";
    std::cout << "b=" << b.get() << "\n";
    assert(!a);
    assert(b);
}
