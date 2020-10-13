#include <list>
#include <iterator>

int main() {
    std::list<int> l = {1, 2, 3, 4};
    //                  ^  ^  ^  ^  ^
    //                begin         end
    // [begin; end)
    std::list<int>::iterator it = l.begin();
    assert(*it == 1);
    *it = 20;
    assert(*it == 20);

    assert(*++it == 2);
    assert(*++it == 3);
    assert(*++it == 4);
    it++;
    assert(it == l.end());
    // *it;  // UB

    std::list<int> l2;
    assert(l2.begin() == l2.end());
    // assert(l.end() == l2.end());
}
