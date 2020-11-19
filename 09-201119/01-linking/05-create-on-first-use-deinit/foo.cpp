#include <iostream>
#include <vector>

std::vector<int>& main_a();

std::vector<int>& foo_a() {
    static std::vector<int> foo_a_ = main_a();
    return foo_a_;
}

namespace {
struct MagicStruct {
    MagicStruct() {
        std::cout << "MagicStruct() from foo\n";
    }
} magic_init;
}  // namespace
