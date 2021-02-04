#ifndef EMPLOYEE_ENUMS_
#define EMPLOYEE_ENUMS_

#include <iosfwd>

namespace employee {
enum class ProgrammingLanguage {
    C,
    Cpp,
    Java,
    Python
};                                     // See PROGRAMMING_LANGUAGE_NAMES.
enum class Region { Russia, EU, US };  // See REGION_NAMES.

std::ostream &operator<<(std::ostream &os, ProgrammingLanguage lang);
std::istream &operator>>(std::istream &is, ProgrammingLanguage &lang);

std::ostream &operator<<(std::ostream &os, Region region);
std::istream &operator>>(std::istream &is, Region &region);
};  // namespace employee

#endif  // EMPLOYEE_ENUMS_
