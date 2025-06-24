#include <stdio.h>
#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;

void enqueue(int val) {
    if((rear + 1) % SIZE == front)
        printf("Circular Queue Overflow\n");
    else {
        if(front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        cq[rear] = val;
    }
}

void dequeue() {
    if(front == -1)
        printf("Circular Queue Underflow\n");
    else {
        printf("Dequeued: %d\n", cq[front]);
        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

void display() {
    if(front == -1)
        printf("Circular Queue is empty\n");
    else {
        printf("Circular Queue: ");
        int i = front;
        while(1) {
            printf("%d ", cq[i]);
            if(i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    enqueue(50);
    display();
    return 0;
}
