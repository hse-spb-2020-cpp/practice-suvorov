#include <utility>

// Начиная с C++17.

struct Foo {
    int x;
    Foo(int x_) : x(x_) {}

    Foo(const Foo&) = delete;
    Foo(Foo&&) = delete;
    Foo& operator=(const Foo&) = delete;
    Foo& operator=(Foo&&) = delete;
};

Foo create_foo(int a, int b) {
    return Foo(a + b);
}

Foo create_foo(int n) {
    if (n == 0) {
        return create_foo(10, 20);
    } else {
        return create_foo(n - 1);
    }
}

int main() {
    Foo f = create_foo(100, &f);
}

// Компилируется примерно в такое:
#if 0
void create_foo2(int a, int b, Foo *retval) {
    new (retval) Foo(a + b);
}

void create_foo2(int n, Foo *retval) {
    if (n == 0) {
        return create_foo2(10, 20, retval);
    } else {
        return create_foo2(n - 1, retval);
    }
}

int main() {
    [[please_no_initialization]] Foo f;
    create_foo2(100, &f);
}
#endif
