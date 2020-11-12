#!/bin/bash
g++ -c main.cpp -std=c++17 -DDEBUG -Wall -Wextra -Werror -O2 -fsanitize=address
g++ -c foo.cpp -std=c++17 -DDEBUG -Wall -Wextra -Werror -O2 -fsanitize=address
g++ -c sum.cpp -std=c++17 -DDEBUG -Wall -Wextra -Werror -O2 -fsanitize=address
g++ main.o foo.o sum.o -o main -Wall -Wextra -Werror -O2

# make, Makefile

