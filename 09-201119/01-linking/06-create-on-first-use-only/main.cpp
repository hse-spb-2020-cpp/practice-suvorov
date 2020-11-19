#include <iostream>
#include <vector>

std::vector<int> &foo_a();

std::vector<int> &main_a() {
    static auto *main_a_ = new std::vector<int>{10, 20, 30};
    return *main_a_;
}

namespace {
struct MagicStruct {
    MagicStruct() {
        std::cout << "MagicStruct() from main\n";
        foo_a().push_back(10);
        foo_a().push_back(20);
    }
} magic_init;
}  // namespace

int main() {
}
