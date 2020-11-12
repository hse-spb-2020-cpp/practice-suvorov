#include <iostream>

struct Foo {
    char a, b;

    Foo();
    void bar();
};

int main() {
    int x = 100;
    Foo f;
    int y = 200;
    int z = 300;
    f.bar();
    return 0;
}
