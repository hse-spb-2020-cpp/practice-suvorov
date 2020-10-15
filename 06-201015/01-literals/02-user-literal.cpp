#include <string>
#include <iostream>

struct BigInt {
    int x;
};

BigInt operator""_BIGINT(const char *c_str) {
    std::string str = c_str;
    return {static_cast<int>(str.length())};
}

int main() {
    BigInt value = 576432658643258432656435876435876487568764875643_BIGINT;
    std::cout << value.x << "\n";
}
