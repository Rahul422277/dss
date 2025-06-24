#include <stdio.h>
#include <ctype.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int main() {
    char postfix[SIZE];
    int i = 0, op1, op2;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    while(postfix[i] != '\0') {
        char ch = postfix[i];
        if(isdigit(ch)) {
            push(ch - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch(ch) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
        i++;
    }

    printf("Result: %d\n", pop());
    return 0;
}
