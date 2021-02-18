#include <vector>
#include <iostream>

struct S {
    int id;
    bool can_copy = true;

    S(int id_) : id(id_) {}

    S(const S &other) = default;

    S &operator=(const S &other) {
        id = other.id;
        can_copy = other.can_copy;
        if (!can_copy) {
            throw 0;
        }
        return *this;
    }
};

int main() {
    std::vector<S> v{1, 2, 3, 4};
    std::vector<S> v2{5, 6, 7, 8};
    v[2].can_copy = false;
    try {
        v2 = v;
    } catch (...) {
        std::cout << "exception!\n";
    }
    // Стандартный вектор не даёт строгую гарантию исключений.
    // Может получиться 1 2 3 8.
    std::cout << v2[0].id << " " << v2[1].id << " " << v2[2].id << " " << v2[3].id << "\n";
}
