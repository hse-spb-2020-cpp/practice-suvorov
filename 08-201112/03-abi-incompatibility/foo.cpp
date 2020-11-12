#include <iostream>

struct Foo {
    int a, b;

    Foo();
    void bar();
};

Foo::Foo() : a(10), b(20) {
}

void Foo::bar() {
    std::cout << a << " " << b << "\n";
}
