#include <vector>
#include <iostream>

struct Foo {
    static inline int last_id = 1;

    int id;
    std::vector<int> a;
    std::vector<int> b;

    Foo() : id(last_id++), a(10), b(20) {
        std::cout << "Foo() " << id << "\n";
        if (id == 5) {
            throw 0;
        }
    }

    ~Foo() {
        std::cout << "~Foo() " << id << "\n";
    }
};

int main() {
    try {
        std::vector<Foo> f(10);
    } catch (...) {
        std::cout << "exception!\n";
    }
}
