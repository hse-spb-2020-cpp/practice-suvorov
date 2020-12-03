#include <iostream>

#define BAR(x) assert(x);
#define FOO(y) int y = 20
#define CHECK(x) if (!x) { std::cout << "error\n"; }

int main() {
    BAR(true), BAR(false);

    int x = 10;
    // FOO(x);
    std::cout << x << "\n";

    // FOO(y), x = 20;

    CHECK(true), CHECK(false);
}
