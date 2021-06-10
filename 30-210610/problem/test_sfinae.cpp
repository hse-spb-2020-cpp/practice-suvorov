#include "doctest.h"
#include <boost/hana.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>

namespace hana = boost::hana;

namespace task_simple_print {
template<typename T>
void simple_print(std::ostream &os, const T &value) {
    // is_same<int, T> ~ struct { static const bool value = true/false; }
    // is_same<int, T>::value
    if constexpr (std::is_same_v<int, T>) {
        os << value;
    } else {
        for (const auto &item : value) {
            os << item;
        }
    }
    if constexpr (false) {
        static_assert(false);
    }
        
    // TODO: use 'if constexpr' and 'is_same<int>'
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
//auto sum(const T &a, const T &b) -> decltype(a + b) {
decltype(std::declval<T>() + std::declval<T>()) sum(const T &a, const T &b) {
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
auto print(std::ostream &os, const T &value) /* TODO: use operator, as well */ {
    os << value;
}

template<typename T>
auto print(std::ostream &os, const T &container) /* TODO: use operator, as well */ {
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
/* TODO */
struct enable_if {};

/* TODO */

template</* TODO */>
using enable_if_t = /* TODO */;

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
auto print_integral(std::ostream &os, const T &value) -> /* TODO: use std::enable_if and std::is_integral */ {
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

namespace task_printer {
template<typename T, typename Dummy = /* TODO: enable_if's default */>
struct printer {
    printer(T) {}
};

template<typename T>
struct printer</* TODO */> {
    T value;
    void print_integral(std::ostream &os) {
        os << value;
    }
};


template<typename T>
struct printer</* TODO */> {
    T value;
    void print_pointer(std::ostream &os) {
        os << value;
    }
};

TEST_CASE("printer") {
    std::stringstream s;
    auto print_integral_is_valid = hana::is_valid([&](auto &v) -> decltype(v.print_integral(s)) {});
    auto print_pointer_is_valid = hana::is_valid([&](auto &v) -> decltype(v.print_pointer(s)) {});

    SUBCASE("int") {
        printer<int> p{123};
        p.print_integral(s);
        CHECK(print_integral_is_valid(p));
        CHECK(!print_pointer_is_valid(p));
        CHECK(s.str() == "123");
        CHECK(std::is_same_v<void, decltype(p.print_integral(s))>);
    }

    SUBCASE("unsigned short") {
        printer<unsigned short> p{static_cast<unsigned short>(123)};
        p.print_integral(s);
        CHECK(print_integral_is_valid(p));
        CHECK(!print_pointer_is_valid(p));
        CHECK(s.str() == "123");
        CHECK(std::is_same_v<void, decltype(p.print_integral(s))>);
    }

    SUBCASE("int*") {
        printer<int*> p{nullptr};
        p.print_pointer(s);
        CHECK(!print_integral_is_valid(p));
        CHECK(print_pointer_is_valid(p));
        CHECK(s.str() == "0");
        CHECK(std::is_same_v<void, decltype(p.print_pointer(s))>);
    }

    SUBCASE("invalid float") {
        printer<float> p{10.0f};
        CHECK(!print_integral_is_valid(p));
        CHECK(!print_pointer_is_valid(p));
    }
}


TEST_CASE("printer CTAD") {
    std::stringstream s;
    auto print_integral_is_valid = hana::is_valid([&](auto &v) -> decltype(v.print_integral(s)) {});
    auto print_pointer_is_valid = hana::is_valid([&](auto &v) -> decltype(v.print_pointer(s)) {});

    SUBCASE("int") {
        printer p{123};
        p.print_integral(s);
        CHECK(print_integral_is_valid(p));
        CHECK(!print_pointer_is_valid(p));
        CHECK(s.str() == "123");
        CHECK(std::is_same_v<void, decltype(p.print_integral(s))>);
    }

    SUBCASE("invalid float") {
        printer p{10.0f};
        CHECK(!print_integral_is_valid(p));
        CHECK(!print_pointer_is_valid(p));
    }
}
};

namespace task_wrapper {
template<typename T>
struct wrapper {
    T value;

    wrapper(T value_) : value(std::move(value_)) {}

    T &get() { return value; }
    const T &get() const { return value; }

    /* TODO */ get_integral() {
        return value;
    }
};

TEST_CASE("wrapper") {
    auto get_integral_is_valid = hana::is_valid([&](auto &v) -> decltype(v.get_integral()) {});

    SUBCASE("int") {
        wrapper<int> w{123};
        CHECK(w.get() == 123);
        CHECK(std::as_const(w).get() == 123);
        CHECK(w.get_integral() == 123);
        CHECK(get_integral_is_valid(w));
        CHECK(std::is_same_v<int, decltype(w.get_integral())>);
    }

    SUBCASE("unsigned short") {
        wrapper<unsigned short> w{123};
        CHECK(w.get() == 123);
        CHECK(std::as_const(w).get() == 123);
        CHECK(w.get_integral() == 123);
        CHECK(get_integral_is_valid(w));
        CHECK(std::is_same_v<unsigned short, decltype(w.get_integral())>);
    }

    SUBCASE("double") {
        wrapper<double> w{123.0};
        CHECK(w.get() == 123.0);
        CHECK(std::as_const(w).get() == 123.0);
        CHECK(!get_integral_is_valid(w));
    }
}
};
