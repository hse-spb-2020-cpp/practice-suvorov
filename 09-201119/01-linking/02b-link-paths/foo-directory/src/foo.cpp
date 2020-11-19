#include "foo.h"
#include "foo_internal.h"
#include <iostream>

namespace foo {
void do_foo() {
    internal::do_foo();
    std::cout << "foo is done!\n";
}
}  // namespace foo
