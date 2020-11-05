#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main() {
    int x = 10;
    auto f = [x = 0 /* C++14 */]() mutable /* rare, because of STL */ {
        return x++;
    };

    std::cout << f() << "\n";
    std::cout << "x=" << x << "\n";

    std::cout << f() << "\n";
    std::cout << "x=" << x << "\n";

    std::cout << f() << "\n";
    std::cout << "x=" << x << "\n";

    std::vector<int> v(3);
    std::generate(v.begin(), v.end(), std::ref(f));

    std::cout << v[0] << " " << v[1] << " " << v[2] << "\n";
    std::cout << f() << "\n";
    std::cout << "x=" << x << "\n";
}
