#include "conditional.h"
#include "conditional.h"  // Test double inclusion
#include "doctest.h"
#include <type_traits>

TEST_CASE("conditional") {
    CHECK(std::is_same_v<
          typename cls_conditional::conditional<true, const int, float>::type,
          const int>);
    CHECK(std::is_same_v<
          typename cls_conditional::conditional<false, int, float &&>::type,
          float &&>);

    CHECK(
        std::is_same_v<typename cls_conditional::conditional<2 * 2 == 4, void,
                                                             const void>::type,
                       void>);
    CHECK(
        std::is_same_v<typename cls_conditional::conditional<2 * 2 == 5, void,
                                                             const void>::type,
                       const void>);

    CHECK(std::is_same_v<
          typename cls_conditional::conditional<2 * 3 == 6, void, void>::type,
          void>);
    CHECK(std::is_same_v<
          typename cls_conditional::conditional<2 * 3 == 7, void, void>::type,
          void>);
}

TEST_CASE("conditional_t") {
    CHECK(std::is_same_v<cls_conditional::conditional_t<true, const int, float>,
                         const int>);
    CHECK(std::is_same_v<cls_conditional::conditional_t<false, int, float &&>,
                         float &&>);

    CHECK(std::is_same_v<
          cls_conditional::conditional_t<2 * 2 == 4, void, const void>, void>);
    CHECK(std::is_same_v<
          cls_conditional::conditional_t<2 * 2 == 5, void, const void>,
          const void>);

    CHECK(std::is_same_v<cls_conditional::conditional_t<2 * 3 == 6, void, void>,
                         void>);
    CHECK(std::is_same_v<cls_conditional::conditional_t<2 * 3 == 7, void, void>,
                         void>);
}
