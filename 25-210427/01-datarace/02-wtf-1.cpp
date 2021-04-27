#include <cassert>
#include <vector>
#include <iostream>
#include <thread>

int main() {
    const int N = 100;
    std::vector<int> v;

    std::thread t1([&]() {
        for (int i = 0; i < N; i++) {
            v.push_back(i);
        }
    });
    while (v.empty()) {};
    assert(!v.empty());
//    std::cout << "v.size()=" << v.size() << "; " << v[0] << "\n";
    for (int i = 0; i < N; i++) {
        v.push_back(1'000'000 + i);
    }
    t1.join();

    std::cout << v.size() << "\n";
    for (int x : v)
        std::cout << " " << x;
    std::cout << "\n";
}
