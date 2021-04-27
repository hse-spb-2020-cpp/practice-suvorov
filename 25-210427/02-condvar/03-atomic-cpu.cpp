#include <atomic>
#include <cassert>
#include <vector>
#include <iostream>
#include <thread>

int main() {
    std::atomic<bool> started = false;
    std::thread t1([&]() {
        int x;
        std::cin >> x;

        started = true;
        std::cout << "world " << x << "\n";
    });
    while (!started) {
    }
    std::cout << "hello\n";
    t1.join();
}
