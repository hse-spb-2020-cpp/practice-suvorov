#include "foo_internal.h"
#include <iostream>

namespace foo::internal {
void do_foo() {
    std::cout << "internal foo is done!\n";
}
}  // namespace foo::internal
