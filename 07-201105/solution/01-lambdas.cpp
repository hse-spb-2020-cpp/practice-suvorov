#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <algorithm>
#include <vector>

int count_even(const std::vector<int> &vec) {
    return std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
}

TEST_CASE("count_even") {
    CHECK(count_even(std::vector<int>{}) == 0);
    CHECK(count_even(std::vector{1, 2, 3, 4, 5}) == 2);
    CHECK(count_even(std::vector{1, 2, 3, 4, 2, 6}) == 4);
}

int count_divisible_by(const std::vector<int> &vec, int modulo) {
    return std::count_if(vec.begin(), vec.end(), [&](int x) { return x % modulo == 0; });
}

TEST_CASE("count_divisible_by") {
    CHECK(count_divisible_by(std::vector<int>{}, 3) == 0);
    CHECK(count_divisible_by(std::vector{1, 2, 3, 4, 5}, 3) == 1);
    CHECK(count_divisible_by(std::vector{1, 2, 3, 4, 2, 6}, 3) == 2);
    CHECK(count_divisible_by(std::vector{1, 2, 3, 4, 2, 6}, 4) == 1);
    CHECK(count_divisible_by(std::vector{1, 2, 3, 4, 2, 6}, 2) == 4);
}

TEST_CASE("sort vectors by length") {
    std::vector<std::vector<int>> data{
        {1, 2, 3},
        {4, 5},
        {6, 7, 8, 9},
        {6, 7, 0, 0},
        {6, 7, 10, 10},
        {1, 1, 1, 1, 1}
    };
    sort(data.begin(), data.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });

    CHECK((data == std::vector<std::vector<int>>{
        {4, 5},
        {1, 2, 3},
        {6, 7, 0, 0},
        {6, 7, 8, 9},
        {6, 7, 10, 10},
        {1, 1, 1, 1, 1}
    }));
}

TEST_CASE("generator") {
    auto generator = [sequence_id = 0]() mutable {
        return sequence_id++;
    };

    CHECK(generator() == 0);
    CHECK(generator() == 1);
    CHECK(generator() == 2);
    CHECK(generator() == 3);
}

TEST_CASE("capture this") {
    struct Foo {
        int modulo;

        int operator()(const std::vector<int> &values) const {
            return std::count_if(values.begin(), values.end(), [this](int value) { return value % modulo == 0; });
        }
    };
    Foo f{3};
    CHECK(f(std::vector{1, 2, 3}) == 1);
    CHECK(f(std::vector{1, 2, 3, 4, 6, 6}) == 3);
}
