#include <vector>

// В другой единице трансляции в конструкторе вызывается push(10).

namespace {
vector<int> foo;
int y;
int z = 20;
}

void push(int x) {
    // foo может быть ещё не проинициализирован, UB.
    foo.push_back(x);

    y++;  // OK

    z++;  // z может быть не проинициализировано, станет 0 --> 1, а потом затрётся.

    static vector<int> foo2;  // Всегда инициализируется при первом прохождении через эту строчку.
    foo2.push_back(x);  // ОК.
}

static vector<int> foo3;  // Снова непонятно, когда инициализируется.

int main() {
}
