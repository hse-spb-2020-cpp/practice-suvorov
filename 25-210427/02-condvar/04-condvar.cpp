#include <atomic>
#include <cassert>
#include <condition_variable>
#include <mutex>
#include <vector>
#include <iostream>
#include <thread>

int main() {
    std::mutex m;
    bool started = false;
    std::condition_variable started_changed;

    std::thread t1([&]() {
        int x;
        std::cin >> x;

        {
            std::unique_lock l(m);
            started = true;
            started_changed.notify_all();
        }
        std::cout << "world " << x << "\n";
    });
    {
        std::unique_lock l(m);
        /*while (!started) {
            started_changed.wait(l);
        }*/
        started_changed.wait(l, [&]() { return started; });
    }
    std::cout << "hello\n";
    t1.join();
}
