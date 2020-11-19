#include <iostream>

// Try adding something like this inside macro:
//    void class_name(); \
//    struct MagicInit { MagicInit() { class_name(); } } magic_init_##class_name; \
//    void class_name()
#define MYTEST_INTERNAL_TEST_CASE(class_name, name) \
    void class_name()

#define MYTEST_INTERNAL_TEST_CASE2(line, name) \
    MYTEST_INTERNAL_TEST_CASE(mytest_test_class_##line, name)
#define MYTEST_INTERNAL_TEST_CASE1(line, name) \
    MYTEST_INTERNAL_TEST_CASE2(line, name)
#define TEST_CASE(name) MYTEST_INTERNAL_TEST_CASE1(__LINE__, name)

/*TEST_CASE("foo")*/ /*MYTEST_INTERNAL_TEST_CASE(mytest_test_class_16, "foo")*/ void mytest_test_class_16() {
    std::cout << "foo\n";
}

TEST_CASE("bar") {
    std::cout << "bar\n";
}

int main() {
    mytest_test_class_16();
    mytest_test_class_20();
}
