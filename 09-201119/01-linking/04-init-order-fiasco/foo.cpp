#include <iostream>
#include <vector>

extern std::vector<int> main_a;
std::vector<int> foo_a = {10, 20, 30};

namespace {
struct MagicStruct {
    MagicStruct() {
        std::cout << "MagicStruct() from foo\n";
    }
} magic_init;
}  // namespace
