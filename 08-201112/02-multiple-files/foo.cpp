#include <iostream>
#include "sum.h"

void foo() {
    std::cout << sum(100, 200) << "\n";
    std::cout << "foo calls bar: " << bar() << "\n";
    std::cout << "foo calls Summer: " << Summer().get_sum() << "\n";
}
