struct Employee {
    virtual int salary() = 0;
};
struct Developer : Employee {
};
struct Manager : Employee {
};

// Контравариантность:
//    S - подтип T
//    vec<T> - подтип vec<S>
// Хорошо работает, если только пишем, плохо работает, если читаем.
void P(vector<std::unique_ptr<Developer>> &x) {
    x.back()  // ????????
}

int main() {
    vector<std::unique_ptr<Employee>> y;
    y.push_back(std::make_unique<Manager>(....));
    P(y);
}
