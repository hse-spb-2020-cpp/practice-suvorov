#include <string>
#include <iostream>

void foo_impl(const std::string &file, int line) {
    std::cout << "called from " << file << ":" << line << "\n";
}

#define foo() foo_impl(__FILE__, __LINE__)
/*void foo() {  // Won't work.
    foo_impl(__FILE__, __LINE__);
}*/

int main() {
    foo();
    foo();
}
