#include <stdio.h>

struct Node {
    int data;
    struct Node* next; // Self-referential pointer
};

int main() {
    struct Node n1, n2;
    n1.data = 10;
    n1.next = &n2;

    n2.data = 20;
    n2.next = NULL;

    printf("n1 data = %d\n", n1.data);
    printf("n2 data = %d\n", n1.next->data);
    return 0;
}
