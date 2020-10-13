#include <iostream>

struct Foo {
    int val1 = 1, val2 = 2;

    Foo(int x) : val1(x) {
        std::cout << x << " | " << val1 << " , " << val2 << "\n";
    }

    /*
    snake_case
    unordered_set
    camelCaseMethod
    CamelCaseClass

    big_int
    unordered_set
    */

    Foo(int x, int y) : Foo(x) {  // delegating constructor
//        Foo(100);  // Wrong: creates a temporary Foo by calling Foo(100).
        val2 = y;
        std::cout << "|" << x << " , " << y << " | " << val1 << " , " << val2 << "\n";
    }
};

int main() {
    Foo f1(10);
    Foo f2(20, 30);
}
