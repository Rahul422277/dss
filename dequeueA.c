#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

void insertFront(int val) {
    if((front == 0 && rear == SIZE - 1) || (front == rear + 1))
        printf("Deque Overflow\n");
    else {
        if(front == -1) front = rear = 0;
        else if(front == 0) front = SIZE - 1;
        else front--;
        deque[front] = val;
    }
}

void insertRear(int val) {
    if((front == 0 && rear == SIZE - 1) || (front == rear + 1))
        printf("Deque Overflow\n");
    else {
        if(front == -1) front = rear = 0;
        else if(rear == SIZE - 1) rear = 0;
        else rear++;
        deque[rear] = val;
    }
}

void deleteFront() {
    if(front == -1)
        printf("Deque Underflow\n");
    else {
        printf("Deleted Front: %d\n", deque[front]);
        if(front == rear) front = rear = -1;
        else if(front == SIZE - 1) front = 0;
        else front++;
    }
}

void deleteRear() {
    if(front == -1)
        printf("Deque Underflow\n");
    else {
        printf("Deleted Rear: %d\n", deque[rear]);
        if(front == rear) front = rear = -1;
        else if(rear == 0) rear = SIZE - 1;
        else rear--;
    }
}

void display() {
    if(front == -1)
        printf("Deque is empty\n");
    else {
        printf("Deque: ");
        int i = front;
        while(1) {
            printf("%d ", deque[i]);
            if(i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();
    deleteFront();
    deleteRear();
    display();
    return 0;
}
