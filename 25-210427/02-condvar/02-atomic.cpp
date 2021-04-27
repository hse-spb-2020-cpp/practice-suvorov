#include <atomic>
#include <cassert>
#include <vector>
#include <iostream>
#include <thread>

int main() {
    std::atomic<bool> started = false;
    std::thread t1([&]() {
        started = true;
        std::cout << "world\n";
    });
    while (!started) {
    }
    std::cout << "hello\n";
    t1.join();
}
