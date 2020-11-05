int main() {
    struct Foo {
        int f;

        void foo() {
            [/*this*/ /*this/* /*f = f*/]() {
                int x = f;
            };
        }
    };
}
