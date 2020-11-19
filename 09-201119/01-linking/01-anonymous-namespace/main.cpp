#include <iostream>

namespace {
int data = 10;

double data_double = 20;
void foo_bar() {
}
}  // namespace

void foo();

namespace {
void bar() {
}
}  // namespace

int main() {
    std::cout << data << "\n";
    foo();
    bar();
}
