struct Node {
    int data = 0;
    Node *prev = nullptr;
    Node *next = nullptr;
};

void insertAfter(Node *anchor, Node *toInsert) {
    // Allways assert preconditions in the beginning.

    // The next two lines are equivalent.
    assert(!toInsert->prev);
    assert(toInsert->prev == nullptr);

    assert(!toInsert->next);
}

int main() {
    Node a, b, c;
    a.data = 1;
    b.data = 2;
    c.data = 3;

    // We would like to create a list of [a, b, c]
    a.prev = TODO;

    printFrom(&a);  // 1 2 3\n
    printFrom(&b);  // 2 3\n

    // Now we would like to swap 'a' and 'b' in the list: [b, a, c]
    a.prev = TODO;

    printFrom(&a);  // 1 3\n
    printFrom(&b);  // 2 1 3\n

    // This code should work 'as is' without any modifications.
    Node d;
    d.data = 50;
    insertAfter(&a, &d);
    printFrom(&a);  // 2 1 50 3\n
    return 0;
}
