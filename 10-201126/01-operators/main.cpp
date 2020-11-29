#include <iostream>
#include <utility>

struct Foo {
    int x;
    std::pair<int, int> p;

    int& operator*() {
        return x;
    }

    //std::pair<int, int>* operator->() {
    auto* operator->() {
        return &p;
    }
};

int main() {
    Foo f{10, {100, 200}};
    std::cout << *f << "\n";  // std::cout << f.operator*() << "\n";
    *f = 20;
    std::cout << *f << "\n";

    std::cout << f->first << "\n";  // std::cout << (f.operator->())->first << "\n";
    f->first = 500;
    std::cout << f->first << "\n";
}
