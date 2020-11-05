#include <iostream>
#include <vector>
#include <utility>

int main() {
    std::vector<int> data{1, 2, 3, 4};

//    auto f = [&data = static_cast<const std::vector<int>&>(data)]() {
    auto f = [&data = std::as_const(data)]() {  // std::as_const is easy.
        std::cout << data.size() << "\n";
        // data.pop_back();
    };
    f();
    data.push_back(10);
    f();
}
