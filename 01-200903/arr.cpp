#include <assert.h>
#include <vector>

void foo(const std::vector<int> &b) {
	assert(b.size() == 1'000'000);
	int x = b[b.size()];
}

int main() {
	std::vector<int> v(1'000'000);
	const int STEPS = 1000;
	for (int i = 0; i < STEPS; i++) {
		foo(v);
	}
}

