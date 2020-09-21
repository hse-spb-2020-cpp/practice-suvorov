#include <assert.h>

// Run under Valgrind to see errors. Sanitazers probably won't help.
int main() {
    {
        int *a = new int;
        *a = 10;  // OK
        assert(*a == 10);
        delete a;
        *a;  // UB: accessing deleted memory.
    }
    {
        int *a = new int;
        delete a;
        a = nullptr;
        delete a;  // OK: special case.
    }
    {
        int *a = new int;
        delete a;
        delete a;  // UB: double delete (double free).
    }
    {
        int *a = new int;
        // Memory leak (not UB): a is not deleted. Memory is kept until the process terminates.
    }
    {
        int x = 10;
        int *a = &x;
        delete a;  // UB: delete called on automatic storage.
    }
}

