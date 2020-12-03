#include <string>
#include <iostream>

int main() {
//    std::string a = "hello world hello world hello world hello world";
    std::string a = "h";
    std::string b(std::move(a));
    // a находится в "moved from" состоянии: мы не знаем, что внутри.
    // См. small string optimization.
    std::cout << "a=" << a << "\n";
    std::cout << "b=" << b << "\n";
}
