#include <iostream>
#include "sum.h"

void foo();

int main() {
    std::cout << sum(10, 20) << "\n";
    std::cout << "main calls bar: " << bar() << "\n";
    std::cout << "main calls Summer: " << Summer().get_sum() << "\n";

    foo();
    return 0;
}
