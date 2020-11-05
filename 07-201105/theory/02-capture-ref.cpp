#include <iostream>

int main() {
    int x = 10;
    std::cout << "x=" << x << "\n";

    auto f = [&x]() {
        std::cout << "f(): " << x << "\n";
        x++;
    };

    f();
    std::cout << "x=" << x << "\n";

    f();
    std::cout << "x=" << x << "\n";
}
