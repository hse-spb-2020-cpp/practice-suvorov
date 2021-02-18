#include <vector>
#include <iostream>

struct Foo {
    static inline int last_id = 1;

    int id;
    std::vector<int> a;
    std::vector<int> b;

    Foo() : id(last_id++), a(10), b(20) {
        std::cout << "Foo() " << id << "\n";
        if (id == 2) {
            throw 0;
        }
    }

    ~Foo() {
        std::cout << "~Foo() " << id << "\n";
    }
};

int main() {
    try {
        std::vector<int> x;
        Foo f[3];
        std::vector<int> y;
    } catch (...) {
        std::cout << "exception!\n";
    }

    {
        Foo *f = new Foo[3];
        delete[] f;
    }
}
