#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <cassert>
#include <cmath>
#include <optional>

// TODO START
struct MinHolder {
};
// TODO END

TEST_CASE("default constructor is enough") {
    MinHolder<int> h;
    h(0);
    CHECK(h.get() == 0);
    h(-10);
    h(-20);
    h(-15);
    CHECK(h.get() == -20);
    h(-20);
    CHECK(h.get() == -20);
    h(-21);
    CHECK(h.get() == -21);
}

TEST_CASE("default constructor is implicit") {
    MinHolder<int> h = {};
    h(0);
    CHECK(h.get() == 0);
}

TEST_CASE("custom comparator with default ctor") {
    MinHolder<int, std::greater<int>> h;
    h(10);
    h(20);
    h(15);
    CHECK(h.get() == 20);
    h(20);
    CHECK(h.get() == 20);
    h(21);
    CHECK(h.get() == 21);
}

TEST_CASE("custom comparator with default ctor") {
    auto cmp = [](int a, int b) { return std::abs(a - 10) < std::abs(b - 10); };
    MinHolder<int, decltype(cmp)> h(cmp);
    h(8);
    h(4);
    CHECK(h.get() == 8);
    h(11);
    CHECK(h.get() == 11);
    h(10);
    CHECK(h.get() == 10);
    h(9);
    CHECK(h.get() == 10);
}

TEST_CASE("default constructor is not enough") {
    MinHolder<int> h;
    h(10);
    h(20);
    h(15);
    CHECK(h.get() == 10);
    h(8);
    CHECK(h.get() == 8);
    h(-100);
    CHECK(h.get() == -100);
}

TEST_CASE("no default constructor") {
    struct Foo {
        explicit Foo(int, int, int) {}
    };
    auto all_equal = [](const auto&, const auto&) { return false; };

    // Hint: use std::optional<> inside MinHolder<>.
    MinHolder<Foo, decltype(all_equal)> h(all_equal);
    h(Foo(1, 2, 3));
    h(Foo(4, 5, 6));
    [[maybe_unused]] Foo f = h.get();
}
