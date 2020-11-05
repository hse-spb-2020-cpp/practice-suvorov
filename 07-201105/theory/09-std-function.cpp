#include <functional>
#include <iostream>

int main() {
    /*std::function<void(int)>*/ auto f = [](int x) {
        std::cout << x << "\n";
//        f(10);
    };
    f(10);
    std::cout << sizeof(f) << "\n";
}
