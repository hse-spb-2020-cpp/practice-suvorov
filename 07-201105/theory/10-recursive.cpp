#include <iostream>

int main() {
    auto fib = [](int n, auto fib) {
        if (n <= 1) return 1;
        return fib(n - 1, fib) + fib(n - 2, fib);
    };
    std::cout << fib(10, fib) << "\n";
}
