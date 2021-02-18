#include <cstddef>
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

template<typename T>
struct vector {
    std::size_t capacity;
    T *data;
    std::size_t size;

    vector(std::size_t n)
        : capacity(n)
        , data(new T[capacity])
        , size(n)
    {
    }

    ~vector() {
        delete[] data;
    }
};

int main() {
    try {
        vector<Foo> f(10);
    } catch (...) {
        std::cout << "exception!\n";
    }
}
