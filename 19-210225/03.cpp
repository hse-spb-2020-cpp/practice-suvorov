#include <optional>
#include <vector>
#include <string>

std::optional<std::string> foo() {
    return "foo";
}

std::vector<std::string> bar() {
    return {"foo", "bar"};
}

int main() {
    std::string s = foo().value();

    std::string s2 = bar()[0];  // move
    auto v = bar();
    std::string s3 = v[0];  // copy from non-const.

    const auto &v2 = bar();
    std::string s4 = v2[0];  // copy from const
}
