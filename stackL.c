#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if(top == NULL)
        printf("Stack Underflow\n");
    else {
        printf("Popped: %d\n", top->data);
        struct Node* temp = top;
        top = top->next;
        free(temp);
    }
}

void display() {
    struct Node* temp = top;
    printf("Stack: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}
