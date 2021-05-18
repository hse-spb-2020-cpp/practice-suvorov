void foo(int a, int b, int c) {
}

int main() {
    int a = (10, 20, 30);  // operator,
    int arr{1, 2, 3};  // НЕ operator,
    foo(1, 2, 3);  // НЕ operator,

    foo((std::cout << "hello", 2), 3, 4);  // foo(2, 3, 4)

    // foo((x, ...)); // foo((x1, x2, x3))  // Так не надо.
    // (f(x), ...);  // f(x1), f(x2), f(x3);  // А вот так осмысленно: 
    // foo(x...);  // foo(x1, x2, x3);  // Так надо.
}
