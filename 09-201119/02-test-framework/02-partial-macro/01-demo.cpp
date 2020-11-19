#include <iostream>

// '\' means 'continue on the next line'.
#define CREATE_TEST \
    void test()

CREATE_TEST {
    std::cout << "this is a test\n";
}

/*CREATE_TEST {
    std::cout << "this is another test\n";
}*/

int main() {
    test();
}
