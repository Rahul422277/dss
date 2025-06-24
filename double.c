#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if(head != NULL)
        head->prev = newNode;
    head = newNode;
}

void deleteNode(int val) {
    struct Node* temp = head;
    while(temp != NULL && temp->data != val)
        temp = temp->next;
    if(temp == NULL) return;

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}

void traverse() {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void count() {
    int c = 0;
    struct Node* temp = head;
    while(temp != NULL) {
        c++;
        temp = temp->next;
    }
    printf("Node Count: %d\n", c);
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    traverse();
    deleteNode(20);
    traverse();
    count();
    return 0;
}
