#include <cassert>
#include <cstddef>  // size_t
#include <iostream>
#include <utility>

template<typename /*struct, class*/ T, std::size_t N> struct array {
    T arr[N]{};

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

private:
    template<typename ArrayType>
    struct iterator_base {
    private:
//        array<T, N> *arr;
        ArrayType *arr;
        std::size_t index;
        iterator_base(ArrayType *arr_, std::size_t index_) : arr(arr_), index(index_) {}

        friend struct array;

    public:
        bool operator!=(const iterator_base &other) const {
            return arr != other.arr || index != other.index;
        }

        iterator_base& operator++() {
            ++index;
            return *this;
        }

        auto& operator*() {
            return arr->arr[index];
        }

        /* auto */
        auto* operator->() {
//            return &*this;
            return &arr->arr[index];
        }
    };

public:
    using iterator = iterator_base<array>;
    using const_iterator = iterator_base<const array>;

    iterator begin() {
        return {this, 0};
    }

    iterator end() {
        return {this, N};
    }

    const_iterator begin() const {
        return {this, 0};
    }

    const_iterator end() const {
        return {this, N};
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

    for (array<int, 10>::iterator it = a.begin(); it != a.end(); ++it) {
        *it += 10;
        std::cout << *it << "\n";
    }

    std::cout << "range-based for:\n";
    for (int x : a) {
        std::cout << "x=" << x << "\n";
    }

    {
        std::cout << "const-ref:\n";
        const auto &ca = a;
        for (array<int, 10>::const_iterator it = ca.begin(); it != ca.end(); ++it) {
            std::cout << *it << "\n";
        }
    }

    {
        array<std::pair<int, int>, 5> ap;
        ap[0].first = 10;
        assert(ap.begin()->first == 10);
    }
}
