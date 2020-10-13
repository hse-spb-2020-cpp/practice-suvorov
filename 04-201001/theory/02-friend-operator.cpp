struct Foo {
    Foo(int) {}

    void operator+=(const Foo &other) {
//       *this
//       other
    }
};

// left-hand side, right-hand side
int operator+(const Foo &lhs, const Foo &rhs) {
}

int main() {
    Foo a = 10;
    a = 20;
    a + 10;
    10 + a;

    // int x;
    // x += a;
}
