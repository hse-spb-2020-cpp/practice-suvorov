#include <ctime>
#include <iostream>
#include <string>
#include <vector>

const int ITERS = 10000;
const int VEC_ITEMS = 1000;
const int ITEM_LENGTH = 100;

std::string foo() {
    std::string x(ITEM_LENGTH, '/'), y;
    // return std::move(x);
    return x;
    // return y;
}

int main() {
    for (int iter = 0; iter < ITERS; iter++) {
        std::vector<std::string> vec;
        for (int item = 0; item < VEC_ITEMS; item++) {
            vec.push_back(foo());
        }
    }
    std::cout << std::clock() * 1.0 / CLOCKS_PER_SEC << " seconds\n";
}
