#include <vector>
#include <iostream>

struct Foo {
    // Если поле полностью создали - у поля вызовется деструктор.
    std::vector<int> a;
    std::vector<int> b;

    // Никаких утечек даже при bad_alloc у b.
    Foo(int x, int y) : a(x), b(y) {
        std::cout << "Foo() started\n";
        throw 0;  // Исключение из конструктора - объект не создан.
        std::cout << "Foo() ended\n";
    }

    ~Foo() {  // Деструктор вызывается только у созданных объектов.
        std::cout << "~Foo()\n";
    }
};

int main() {
    try {
        Foo f(10, 20);
    } catch (...) {
        // Не можем получить доступ к 'f'.
    }
}
