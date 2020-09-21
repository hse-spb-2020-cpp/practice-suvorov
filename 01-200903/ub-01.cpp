#include <iostream>

int main() {
	int x = 10;
	int y = (x++) + (x++);
	std::cout << y << "\n";
}

