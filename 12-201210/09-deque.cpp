#include <cassert>
#include <deque>
#include <vector>

int main() {
    {
        std::vector<int> v = {10};
        int &x = v[0];
        v.push_back(20);
        // x - dandling reference (висячая ссылка), обращаться к ней нельзя.
    }
    {
        std::deque<int> v = {10};
        int &x = v[0];
        v.push_back(20);
        v.push_front(30);
        assert(x == 10);
    }
}
