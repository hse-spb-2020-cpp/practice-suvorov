#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

auto is_divisible_by(int modulo) {
    return [modulo](int x) { return x % modulo == 0; };
}

TEST_CASE("is_divisible_by") {
    {
        auto divisible_by_2 = is_divisible_by(2);
        CHECK(!divisible_by_2(1));
        CHECK(divisible_by_2(2));
        CHECK(!divisible_by_2(3));
        CHECK(divisible_by_2(4));
        CHECK(!divisible_by_2(5));
        CHECK(divisible_by_2(6));
    }
    {
        auto divisible_by_5 = is_divisible_by(5);
        CHECK(!divisible_by_5(1));
        CHECK(!divisible_by_5(2));
        CHECK(divisible_by_5(5));
        CHECK(!divisible_by_5(6));
        CHECK(!divisible_by_5(7));
        CHECK(!divisible_by_5(8));
        CHECK(divisible_by_5(10));
    }
}

TEST_CASE("copy this") {
    struct Foo {
        int modulo;

        auto to_lambda() const {
            return [*this](int value) { return value % modulo == 0; };
        }
    };
    auto divisible_by_2 = Foo{2}.to_lambda();
    CHECK(!divisible_by_2(1));
    CHECK(divisible_by_2(2));
    CHECK(!divisible_by_2(3));
    CHECK(divisible_by_2(4));
    CHECK(!divisible_by_2(5));
    CHECK(divisible_by_2(6));
}
