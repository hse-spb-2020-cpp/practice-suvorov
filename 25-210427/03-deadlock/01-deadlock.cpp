#include <cassert>
#include <cstdlib>
#include <mutex>
#include <thread>

int main(int argc, char *argv[]) {
    assert(argc == 2);
    const int N = std::atoi(argv[1]);
    std::mutex m1, m2;

    std::thread t1([&]() {
        // latch
        for (int i = 0; i < N; i++) {
            std::unique_lock l1(m1);
            std::unique_lock l2(m2);
        }
    });

    std::thread t2([&]() {
        // latch
        for (int i = 0; i < N; i++) {
            std::unique_lock l2(m2);
            std::unique_lock l1(m1);
        }
    });

    t2.join();
    t1.join();
}
