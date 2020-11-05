#include <iostream>

template<typename> struct TD;

int main() {
    auto f = []() -> long long {
        return 10;
    };
    TD<decltype(f())>{};
}
