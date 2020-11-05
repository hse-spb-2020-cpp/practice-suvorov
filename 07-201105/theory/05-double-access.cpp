#include <iostream>

int main() {
    int x = 10;
    
    auto f = [&x]() { x++; };
    auto g = [&x]() { x += 2; };

    std::cout << x << "\n";
    f();
    std::cout << x << "\n";
    g();
    std::cout << x << "\n";
    f();
    std::cout << x << "\n";
}
