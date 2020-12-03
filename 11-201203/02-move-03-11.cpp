#include <ctime>
#include <iostream>
#include <string>
#include <vector>

const int ITERS = 10000;
const int VEC_ITEMS = 1000;
const int ITEM_LENGTH = 100;

/*
void push_back(const T &value) {  // C++03, C++11
    data[length++] = value;
}
void push_back(T &&value) {  // C++11
    data[length++] = std::move(value);
}
*/

int main() {
    for (int iter = 0; iter < ITERS; iter++) {
        std::vector<std::string> vec;
        for (int item = 0; item < VEC_ITEMS; item++) {
            vec.push_back(std::string(ITEM_LENGTH, '?'));
        }
    }
    std::cout << std::clock() * 1.0 / CLOCKS_PER_SEC << " seconds\n";
}
