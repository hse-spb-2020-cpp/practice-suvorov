#include <atomic>
#include <cassert>
#include <condition_variable>
#include <mutex>
#include <vector>
#include <iostream>
#include <thread>

int main() {
    latch l(2);  // C++20 only, GCC 11+

    std::thread t1([&]() {
        int x;
        std::cin >> x;
        l.arrive_and_wait();
        std::cout << "world " << x << "\n";
    });
    l.arrive_and_wait();
    std::cout << "hello\n";
    t1.join();
}
