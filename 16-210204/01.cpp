#include <algorithm>

// Принцип подстановки Лисков (часть принципов SOLID):
// Пусть есть свойство P(x), верно для всех x - объект типа T.
// Тогда для всех y - объект типа S (S - наследние T) P(y) тоже верно.

struct list {
    virtual void push_back(int value);  // REQUIRES(true)
    void pop_back();
    void merge(list &other);

    std::size_t size();

    int &back();
};

struct sorted_list : list {
    void push_back(int value) override;  // REQUIES(value is the maximum) или сортирует автоматически
};

void P(list &x) {
    x.push_back(2);
    x.push_back(1);
    CHECK(x.back() == 1);
}

{
    sorted_list l;
    P(l);
}
