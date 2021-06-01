#include "stateless_manip.h"
#include "stateless_manip.h"  // Test double inclusion
#include <sstream>
#include "doctest.h"

TEST_CASE("writer") {
    std::stringstream s;
    SUBCASE("temporary") {
        s << ' ' << cls_stateless_manip::shifted(10, 12345) << 'y';
        CHECK(s.str() == " 12355y");
    }
    SUBCASE("variable") {
        int y = 12345;
        s << ' ' << cls_stateless_manip::shifted(10, y) << 'y';
        CHECK(s.str() == " 12355y");
    }
}

TEST_CASE("reader") {
    std::stringstream s;
    SUBCASE("simple") {
        s << "12355";
    }
    SUBCASE("complex") {
        s << " 12355y";
    }
    int y = -1;
    s >> cls_stateless_manip::shifted(10, y);
    // s >> cls_stateless_manip::shifted(10, 123);  // TODO: should not compile
    CHECK(y == 12345);
}
