#include <cassert>
#include <algorithm>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>

namespace class200917 {
struct Ratio {
private:
    struct no_normalize_tag {};

    int num, denom;

    void normalize() {
        int d = std::gcd(num, denom);
        num /= d;
        denom /= d;
        if (denom < 0) {
            num = -num;
            denom = -denom;
        }
    }

    Ratio(no_normalize_tag, int num_, int denom_) : num(num_), denom(denom_) {
    }

public:
    Ratio(int value = 0) : num(value), denom(1) {}
//    Ratio() : num(0), denom(1) {}
//    Ratio() : Ration(0) {  // delegating constructor
//    }
    Ratio(int num_, int denom_) : num(num_), denom(denom_) {
        normalize();
    }

    Ratio operator+() const {
        return {no_normalize_tag(), num, denom};
    }

    Ratio operator-() const {
        return {no_normalize_tag(), -num, denom};
    }

    Ratio& operator++() {
        num += denom;
        return *this;
    }

    Ratio& operator--() {
        num -= denom;
        return *this;
    }

    #if 0
    Ratio operator+(const Ratio &b) const {
        const Ratio &a = *this;
        return {
            a.get_num() * b.get_denom() + b.get_num() * a.get_denom(),
            a.get_denom() * b.get_denom()
        };
    }
    #endif

    [[nodiscard]] int get_num() const { return num; }
    [[nodiscard]] int get_denom() const { return denom; }
};

#if 1
Ratio operator+(const Ratio &a, const Ratio &b) {
    return {
        a.get_num() * b.get_denom() + b.get_num() * a.get_denom(),
        a.get_denom() * b.get_denom()
    };
}
#endif

Ratio operator-(const Ratio &a, const Ratio &b) {
    return a + (-b);
}

Ratio& operator+=(Ratio &a, const Ratio &b) {
    return a = a + b;
}

Ratio operator++(Ratio &r, int) {
    Ratio old = r;
    ++r;
    return old;
}

std::ostream& operator<<(std::ostream &os, const Ratio &r) {
    return os << r.get_num() << '/' << r.get_denom();
}

std::istream& operator>>(std::istream &is, Ratio &r) {
    int num;
    is >> num;
    assert(is);

    char sep;
    is >> sep;
    assert(is);
    assert(sep == '/');

    int denom;
    is >> denom;
    assert(is);

    r = {num, denom};
    return is;
}

}  // namespace class200917

int main() {
    using class200917::Ratio;
    {
        Ratio r = 10;
        assert(r.get_num() == 10);
        assert(r.get_denom() == 1);
    }
    {
        Ratio r = {-10, 6};
        assert(r.get_num() == -5);
        assert(r.get_denom() == 3);
    }
    {
        Ratio r = {-10, 6};
        Ratio r2 = 10 + r;  // REQUIRES operator+(const Ratio&, const Ratio&), not Ratio::operator+(const Ratio&)
        //10.operator+(r)  // Oops.
        //operator+(10, r)  // Works.

        std::stringstream s;
        s << r2;
        assert(r2.get_num() == 25);
        assert(r2.get_denom() == 3);
        assert(s.str() == "25/3");
    }
}
