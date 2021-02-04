#include <algorithm>

// Принцип подстановки Лисков (часть принципов SOLID):
// Пусть есть свойство P(x), верно для всех x - объект типа T.
// Тогда для всех y - объект типа S (S - наследние T) P(y) тоже верно.

struct sorted_list {
    virtual void push_back(int value);  // Нет гарантии, что это будет именно последний элемент.
    void pop_back();
    void merge(sorted_list &other);

    std::size_t size();

    int &back();  // Упс: есть гарантия, что тут максимум.
};

struct list : sorted_list {
    virtual void push_back(int value);
    void pop_back();
    void merge(list &other);

    std::size_t size();

    int &back();
};

void P(sorted_list &x) {
    x.push_back(2);
    x.push_back(1);
    CHECK(x.back() >= 2);
}

{
    list l;
    P(l);
}
