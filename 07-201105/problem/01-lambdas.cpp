#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <algorithm>
#include <vector>

// TODO START
??? count_even(???) {
}
// TODO END

TEST_CASE("count_even") {
    CHECK(count_even(std::vector<int>{}) == 0);
    CHECK(count_even(std::vector{1, 2, 3, 4, 5}) == 2);
    CHECK(count_even(std::vector{1, 2, 3, 4, 2, 6}) == 4);
}

// TODO START
??? count_divisible_by(???) {
}
// TODO END

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
    // TODO START
    sort(data.begin(), data.end());
    // TODO END

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
    auto generator = ???;

    CHECK(generator() == 0);
    CHECK(generator() == 1);
    CHECK(generator() == 2);
    CHECK(generator() == 3);
}
