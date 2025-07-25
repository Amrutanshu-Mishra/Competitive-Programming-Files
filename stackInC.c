#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

//Defining the constructor
void stackConstructor(struct Stack* stk){
    stk->top = -1;
}

//Defining PUSH operation
void push(struct Stack* stk, int a){
    if(stk->top == 99){
        printf("Stack overflow!");
        return;
    }
    stk->top++;
    stk->arr[stk->top] = a;
}

//Defining POP operation
void pop(struct Stack*stk){
    if(stk->top == -1){
        printf("Stack underflow!");
        return;
    }
    stk->top--;
}

//Defining TOP operation
int top(struct Stack*stk){
    if(stk->top == -1){
        printf("The stack is empty");
        return -1;
    }
    return stk->arr[stk->top];
}

//Defining isEmpty operation
bool isEmpty(struct Stack*stk){
    return stk->top == -1;
}

int main() {
    struct Stack s;
    stackConstructor(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", top(&s));  // Should print 30
    pop(&s);
    printf("Top element after pop: %d\n", top(&s));  // Should print 20

    while (!isEmpty(&s)) {
        printf("Popped: %d\n", top(&s));
        pop(&s);
    }

    pop(&s);  // Should show underflow

    return 0;
}
