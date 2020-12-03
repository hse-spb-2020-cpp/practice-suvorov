#include <algorithm>
#include <cassert>
#include <utility>

template<typename T>
struct unique_ptr {
    T *data;

    unique_ptr(T *data_ = nullptr) : data(data_) {}

    unique_ptr(const unique_ptr &other) = delete;
    unique_ptr(unique_ptr &&other)
        : data(std::exchange(other.data, nullptr)) {  // OK
    }

    unique_ptr& operator=(unique_ptr &&other) {  // No UB, no leaks, but BAD (see `main`).
        using std::swap;
        swap(data, other.data);
        return *this;
    }

    ~unique_ptr() {
        delete data;
    }
};

int main() {
    unique_ptr<int> p0b{nullptr};  // OK: `delete nullptr;` is valid
    unique_ptr<int> p1{new int(10)};
    unique_ptr<int> p2{new int(20)};
    p2 = std::move(p1);
    assert(!p1.data);  // Oops.
}
