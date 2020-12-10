#include <utility>

struct Foo {
    int x;
    Foo(int x_) : x(x_) {}

    Foo(const Foo&) = delete;
    Foo(/* const */ Foo&&) {};
    Foo& operator=(const Foo&) = delete;
    Foo& operator=(/* const */ Foo&&) = delete;
};

Foo create_foo(int a, int b) {
    Foo f(a + b);
    static Foo global_f(30);
    return f;
}

int main() {
    {
        Foo f(10);
        Foo g = std::move(f);
    }
    {
        Foo f = create_foo(10, 20);
    }
}
