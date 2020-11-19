#include <iostream>

int foo_a = 20;

namespace {
struct MagicStruct {
    MagicStruct() {
        std::cout << "MagicStruct()\n";
    }
} magic_init;
}  // namespace
