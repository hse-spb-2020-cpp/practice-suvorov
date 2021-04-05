#include <cstddef>
#include <vector>
#include <iostream>
#include <memory>

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

template<typename T, typename Alloc = std::allocator<T>>
struct vector {
    std::size_t capacity;
    T *data;
    std::size_t size;

    vector(std::size_t n)
        : capacity(n)
        , data(Alloc().allocate(capacity))
        , size(n)
    {
        for (std::size_t i = 0; i < size; i++) {
            try {
                // 05.04.2021: не факт, что так вообще можно делать, кстати: может быть UB: https://stackoverflow.com/questions/66365928/is-it-ub-to-placement-new-datai-instead-of-data-i
                // Но мы на курсе делаем и считаем, что не взорвётся. Самостоятельно писать vector<> не надо.
                new (data + i) T();
                // new (&data[i]) T();
            } catch (...) {
                for (std::size_t j = 0; j < i; j++) {
                    data[j].~T();
                }
                // delete data;  // unique_ptr<T>
                // delete[] data;  // unique_ptr<T[]>
                Alloc().deallocate(data, capacity);
                throw;
            }
        }
    }

    ~vector() {
        for (std::size_t i = 0; i < size; i++) {
            // (data + i)->~T();
            // (&data[i])->~T();
            data[i].~T();
        }
        Alloc().deallocate(data, capacity);
    }
};

int main() {
    try {
        vector<Foo> f(10);
        std::cout << "f constructed\n";
    } catch (...) {
        std::cout << "exception!\n";
    }
}
