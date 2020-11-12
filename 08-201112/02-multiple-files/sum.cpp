#include <cassert>
#include "sum.h"

int sum(int a, int b) {  // If mismatched: IFNDR (Ill-Formed, No Diagnostics Required)
    assert(a >= 0);
    return a + b;
}

Summer::Summer() : a(100), b(2000) {
}

int Summer::get_sum() const {
    return a + b;
}
