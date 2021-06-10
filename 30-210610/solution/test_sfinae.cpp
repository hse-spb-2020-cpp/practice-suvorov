#include "doctest.h"
#include <boost/hana.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

namespace hana = boost::hana;

namespace task_simple_print {
template<typename T>
void simple_print(std::ostream &os, const T &value) {
    if constexpr (std::is_same_v<T, int>) {
        os << value;
    } else {
        for (const auto &item : value) {
            os << item;
        }
    }
}

TEST_CASE("simple_print") {
    std::stringstream s;

    SUBCASE("int") {
        simple_print(s, 123);
        CHECK(s.str() == "123");
        CHECK(std::is_same_v<void, decltype(simple_print(s, 123))>);
    }

    SUBCASE("vector<int>") {
        std::vector<int> v{10, 20, 30};
        simple_print(s, v);
        CHECK(s.str() == "102030");
        CHECK(std::is_same_v<void, decltype(simple_print(s, v))>);
    }
}
}

namespace task_sum {
template<typename T>
auto sum(const T &a, const T &b) -> decltype(a + b) {
    return a + b;
}

TEST_CASE("sum") {
    auto sum_is_valid = hana::is_valid([](auto a, auto b) -> decltype(sum(a, b)) {});
    static_assert(sum_is_valid(1, 2));

    CHECK(sum(1, 2) == 3);
    CHECK(sum_is_valid(1, 2));
    CHECK(sum(std::string("a"), std::string("b")) == "ab");
    CHECK(sum_is_valid(std::string("a"), std::string("b")));

    std::stringstream s;
    CHECK(!sum_is_valid(s, s));
}
}

namespace task_print {
template<typename T>
auto print(std::ostream &os, const T &value) -> decltype(os << value, void()) {
    os << value;
}

template<typename T>
auto print(std::ostream &os, const T &container) -> decltype(os << *container.begin(), void()) {
    for (const auto &v : container) {
         os << v;
    }
}

TEST_CASE("print") {
    std::stringstream s;
    auto print_is_valid = hana::is_valid([&](const auto &v) -> decltype(print(s, v)) {});

    SUBCASE("int") {
        print(s, 123);
        CHECK(print_is_valid(123));
        CHECK(s.str() == "123");
        CHECK(std::is_same_v<void, decltype(print(s, 123))>);
    }

    SUBCASE("vector<int>") {
        std::vector<int> v{10, 20, 30};
        print(s, v);
        CHECK(print_is_valid(v));
        CHECK(s.str() == "102030");
        CHECK(std::is_same_v<void, decltype(print(s, v))>);
    }

    SUBCASE("invalid") {
        CHECK(!print_is_valid(s));
    }
}
}

namespace task_enable_if {
template<bool Value, typename T = void>
struct enable_if {};

template<typename T>
struct enable_if<true, T> {
    using type = T;
};

template<bool Value, typename T = void>
using enable_if_t = typename enable_if<Value, T>::type;

TEST_CASE("enable_if") {
    CHECK(std::is_same_v<typename enable_if<true, const int&&>::type, const int&&>);
    CHECK(std::is_same_v<typename enable_if<true>::type, void>);

    CHECK(std::is_same_v<enable_if_t<true, const int&&>, const int&&>);
    CHECK(std::is_same_v<enable_if_t<true>, void>);

    auto has_type = hana::is_valid([](auto x) -> typename decltype(x)::type {});
    CHECK(has_type(enable_if<true, const int&&>()));
    CHECK(has_type(enable_if<true>()));
    CHECK(!has_type(enable_if<false, const int&&>()));
    CHECK(!has_type(enable_if<false, int>()));
    CHECK(!has_type(enable_if<false>()));
}
}

namespace task_print_integral {
template<typename T>
auto print_integral(std::ostream &os, const T &value) -> std::enable_if_t<std::is_integral_v<T>> {
    os << value;
}

TEST_CASE("print_integral") {
    std::stringstream s;
    auto print_integral_is_valid = hana::is_valid([&](const auto &v) -> decltype(print_integral(s, v)) {});

    SUBCASE("int") {
        print_integral(s, 123);
        CHECK(print_integral_is_valid(123));
        CHECK(s.str() == "123");
        CHECK(std::is_same_v<void, decltype(print_integral(s, 123))>);
    }

    SUBCASE("unsigned short") {
        unsigned short v = 123;
        print_integral(s, v);
        CHECK(print_integral_is_valid(v));
        CHECK(s.str() == "123");
        CHECK(std::is_same_v<void, decltype(print_integral(s, v))>);
    }

    SUBCASE("invalid") {
        CHECK(!print_integral_is_valid(1.0));
        CHECK(!print_integral_is_valid(1.0f));
        CHECK(!print_integral_is_valid("hi"));
        CHECK(!print_integral_is_valid(nullptr));
    }
}
}
