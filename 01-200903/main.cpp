#include <iostream>
#include <vector>

/*
int& foo() {
    int x = 5;
    return x;
}

int bar() {
}
*/

int main() {
    int a[10];
    a[0] = 10;
    a[100] = 0;
    std::cout << "Hello World!\n";
    std::cout << a[0] << "\n";
}

