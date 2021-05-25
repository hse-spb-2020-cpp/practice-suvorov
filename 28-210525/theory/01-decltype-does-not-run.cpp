#include <iostream>

int foo() {
    std::cout << "hi\n";
    return 10;
}

int main() {
    // decltype() никогда не вычисляет выражение.
    [[maybe_unused]] decltype(foo()) x = 10;
    std::cout << "x defined\n";
}
