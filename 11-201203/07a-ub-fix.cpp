#include <algorithm>
#include <cassert>
#include <utility>

template<typename T>
struct unique_ptr {
    T *data;

    unique_ptr(unique_ptr &&other)
        : data(std::exchange(other.data, nullptr)) {  // OK
    }

    ~unique_ptr() {
        delete data;
    }
};

int main() {
    // unique_ptr<int> p0a;  // ub in destructor
    unique_ptr<int> p0b{nullptr};  // OK: `delete nullptr;` is valid
    unique_ptr<int> p1{new int(10)};
    unique_ptr<int> p2(std::move(p1));

    // T* works alike.
    int x = 10;
    int y = std::move(x);
    assert(x == 10);
    assert(y == 10);
}
