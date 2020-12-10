#include <cassert>
#include <memory>
#include <vector>

template<typename T>
T&& my_move(T& v) {
    return static_cast<T&&>(v);
}

int main() {
    // moved-from состояние для *_ptr: nullptr
    {
        std::unique_ptr<int> x(new int(10));
        std::unique_ptr<int> y = my_move(x);
        assert(!x);
    }

    {
        std::shared_ptr<int> x(new int(10));
        std::shared_ptr<int> y = my_move(x);
        assert(!x);
    }

    // moved-from состояние для остальных: что угодно корректное.
    // Можно перезаписать, можно уничтожить.
    {
        std::vector<int> x(1, 2, 3, 4);
        std::vector<int> y = my_move(x);
        x.push_back(30);  // Можно, но мы не знаем префикс 'x'.
        x.clear();
        x.resize(50);
    }
}
