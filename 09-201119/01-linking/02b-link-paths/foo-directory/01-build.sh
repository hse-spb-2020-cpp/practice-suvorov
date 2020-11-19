#!/bin/bash
g++ src/foo.cpp -Iinclude -c -o foo.o
g++ src/foo_internal.cpp -Iinclude -c -o foo_internal.o
ar -rcs libfoo.a foo.o foo_internal.o
