#include <cassert>
#include <cstddef>  // size_t
#include <iostream>

template<typename /*struct, class*/ T, std::size_t N> struct array {
    T arr[N];

    /* auto */
    std::size_t size() const {
        return N;
    }

    /* auto& */
    T& operator[](std::size_t i) {
        return arr[i];
    }

    /* auto& OR const auto& */
    const T& operator[](std::size_t i) const {
        return arr[i];
    }
};

int main() {
    array<int, 10> a;
    assert(a.size() == 10);
    a[0] = 10;
    assert(a[0] == 10);

    {
        const array<int, 10> &ca = a;
        assert(ca[0] == 10);
    }

/*    for (auto it = a.begin(); it != a.end(); it++) {
        std::cout << *it << "\n";
    }*/
}
