#ifndef SUM_H_
#define SUM_H_

//using namespace std;
//using std::cout;
//#define x y

int sum(int a, int b);

struct Summer {
    int a, b;

    Summer();
    int get_sum() const;
};

inline int bar() {
    return 123;
}

/*
void foo_invariant();
template<typename T> struct Foo {
    void invariant() { foo_invariant(); }
};
*/

#endif  // SUM_H_
