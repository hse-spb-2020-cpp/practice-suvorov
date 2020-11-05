#include <iostream>

int main() {
    auto f = [](auto x) {  // C++14 for lambdas; C++20 for functions.
        return x + 1;
    };

    auto g = []<typename T>(T x, T y) {  // C++20
        return x + y;
    };

    std::cout << f(10) << "\n";
    std::cout << f(10.5) << "\n";
}
