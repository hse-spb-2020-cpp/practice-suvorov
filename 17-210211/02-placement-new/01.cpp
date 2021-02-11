#include <new>
#include <iostream>

/*
template<typename T>
struct optional {
    T *value;
    bool exists;
};
*/

struct Foo {
    int x = 10, y = 20;
    Foo() {
        std::cout << "Foo()\n";
    }
    Foo(const Foo&) = delete;
    ~Foo() {
        std::cout << "~Foo()\n";
    }
};

int main() {
    alignas(Foo) char buf[sizeof(Foo)];  // Важно: это (unsigned/signed) char.
                                         // Не int, short, float, std::byte, int8_t.
    alignas(alignof(Foo)) char buf2[sizeof(Foo)];

    std::cout << "alignof(Foo)=" << alignof(Foo) << "\n";  // alignof() для любого типа - степень двойки.

    // Осторожно, не надо пытаться делать что-то очень хитрое: strict aliasing.
    Foo *foo = reinterpret_cast<Foo*>(&buf[0]);
    Foo *foo2 = static_cast<Foo*>(static_cast<void*>(&buf[0]));
    Foo *foo3 = static_cast<Foo*>(static_cast<void*>(buf /* array-to-pointer decay */));

    new (foo) Foo();  // placement new, лежит в <new>
    std::cout << foo->x << "\n";
    foo->~Foo();
//    delete foo;  // UB
}
