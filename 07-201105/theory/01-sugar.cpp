#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

int main() {
    auto f = [](int a, int b) { return a > b; };
    std::cout << sizeof(f) << "\n";
}
