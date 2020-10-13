operator<=(...) {
     return a < b || a == b;
}

operator!=(...) {
     return a < b || b < a;
}

enum CompareResult { LESS, EQUAL, GREATER };

CompareResult compare(....) {
}

C++20:    operator<=>  (spaceship operator)
std::strict_ordering
