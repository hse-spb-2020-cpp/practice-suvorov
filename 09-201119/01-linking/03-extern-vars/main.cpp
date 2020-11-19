#include <iostream>

int main_a = 10;
extern int foo_a;

int main() {
    std::cout << main_a << "\n";
    std::cout << foo_a << "\n";
}
