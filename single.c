#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void deleteNode(int val) {
    struct Node *temp = head, *prev = NULL;
    if(temp != NULL && temp->data == val) {
        head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void traverse() {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverse() {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
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
    printf("Linked List: ");
    traverse();
    deleteNode(20);
    printf("After Deletion: ");
    traverse();
    count();
    reverse();
    printf("After Reversing: ");
    traverse();
    return 0;
}
