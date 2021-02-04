#include "employee_enums.h"
#include <cassert>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>

namespace employee {
namespace {
constexpr const char *PROGRAMMING_LANGUAGE_NAMES[] = {"C", "C++", "Java",
                                                      "Python"};
constexpr const char *REGION_NAMES[] = {"Russia", "EU", "US"};
}  // namespace

std::ostream &operator<<(std::ostream &os, ProgrammingLanguage lang) {
    auto lang_id = static_cast<std::size_t>(lang);
    assert(lang_id < std::size(PROGRAMMING_LANGUAGE_NAMES));
    return os << PROGRAMMING_LANGUAGE_NAMES[lang_id];
}

std::istream &operator>>(std::istream &is, ProgrammingLanguage &lang) {
    std::string name;
    if (!(is >> name)) {
        return is;
    }
    for (std::size_t i = 0; i < std::size(PROGRAMMING_LANGUAGE_NAMES); i++) {
        if (name == PROGRAMMING_LANGUAGE_NAMES[i]) {
            lang = static_cast<ProgrammingLanguage>(i);
            return is;
        }
    }
    is.setstate(std::istream::failbit);
    return is;
}

std::ostream &operator<<(std::ostream &os, Region region) {
    auto region_id = static_cast<std::size_t>(region);
    assert(region_id < std::size(REGION_NAMES));
    return os << REGION_NAMES[region_id];
}

std::istream &operator>>(std::istream &is, Region &region) {
    std::string name;
    if (!(is >> name)) {
        return is;
    }
    for (std::size_t i = 0; i < std::size(REGION_NAMES); i++) {
        if (name == REGION_NAMES[i]) {
            region = static_cast<Region>(i);
            return is;
        }
    }
    is.setstate(std::istream::failbit);
    return is;
}
}  // namespace employee
