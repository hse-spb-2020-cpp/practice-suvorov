#include <cassert>
#include <cstddef>  // std::size_t
#include <iostream>

template<typename /*struct, class*/ T, std::size_t N> struct array {
    T arr[N];

    auto size() const {
        return N;
    }

    void botva() {
        arr[0].foobar();
        x++;
    }
};

int main() {
    array<int, 10> a;
    assert(a.size() == 10);
/*    if (false) {
      a.botva();
    }*/
//    a[0] = 10;
//    assert(a[0] == 10);

/*    for (auto it = a.begin(); it != a.end(); it++) {
        std::cout << *it << "\n";
    }*/
}
