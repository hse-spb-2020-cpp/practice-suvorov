#include <cassert>
#include <memory>
#include <utility>

struct Foo {
    std::unique_ptr<int> p;

//    Foo(const std::unique_ptr<int> &p_origin)
//        : p(p_origin) {}

//    Foo(std::unique_ptr<int> &&p_origin)
//        : p(p_origin.release()) {}

/*    Foo(std::unique_ptr<int> &&p_origin)
        : p(std::move(p_origin)) {
        assert(!p_origin);
    }*/

    Foo(std::unique_ptr<int> p_origin)
        : p(std::move(p_origin)) {
        assert(!p_origin);
    }
};

int main() {
    std::unique_ptr<int> p = std::make_unique<int>(10);
    std::move(p);  // no op
    assert(p);

//    Foo f{std::make_unique<int>(20)};
    //Foo f{std::move(p)};  // std::unique_ptr<int> p_origin = p;
    Foo f{p};
    assert(!p);
}
