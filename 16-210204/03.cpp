struct Employee {
    virtual int salary() = 0;
};
struct Developer : Employee {
};
struct Manager : Employee {
};

// Ковариантность:
//    S - подтип T
//    vec<S> - подтип vec<T>
// Хорошо работает, если только читаем, плохо работает, если пишем.
void P(vector<std::unique_ptr<Employee>> &x) {
    x.push_back(std::make_unique<Manager>(.....));
}

int main() {
    vector<std::unique_ptr<Developer>> y;
    P(y);
}
