#include <cassert>
#include <vector>
#include <iostream>
#include <thread>

int main() {
    const int N = 100;
    std::vector<int> v;
    bool started = false;

    std::thread t1([&]() {
        started = true;
        for (int i = 0; i < N; i++) {
            v.push_back(i);
        }
    });
    while (!started) {
    }
    assert(started);
    for (int i = 0; i < N; i++) {
        v.push_back(1'000'000 + i);
    }
    t1.join();

    std::cout << v.size() << "\n";
    for (int x : v)
        std::cout << " " << x;
    std::cout << "\n";
}
