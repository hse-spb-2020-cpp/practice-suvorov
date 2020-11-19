#include <iostream>
#include <vector>

std::vector<int> main_a = {10, 20, 30};
extern std::vector<int> foo_a;

namespace {
struct MagicStruct {
    MagicStruct() {
        std::cout << "MagicStruct() from main\n";
        foo_a.push_back(10);
        foo_a.push_back(20);
        std::cout << "foo_a.size() == " << foo_a.size() << "\n";
    }
} magic_init;
}  // namespace

int main() {
}
