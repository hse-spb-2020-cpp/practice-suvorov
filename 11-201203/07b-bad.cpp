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

    unique_ptr& operator=(unique_ptr &&other) {  // NOT OK: leaks old `data`
        if (this == &other) {
            return *this;
        }
        // ~~ auto tmp = other.data;
        //    other.data = nullptr;
        //    data = tmp;
        data = std::exchange(other.data, nullptr);
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
    assert(!p1.data);
}
