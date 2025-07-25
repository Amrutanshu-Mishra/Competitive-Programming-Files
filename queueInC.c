#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 100
struct Queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

//constructor
void queueInit(struct Queue*q){
    q->front = -1;
    q->rear=-1;
}

//implementing ENQUEUE
void enqueue(struct Queue*q, int val){
    //OVERFLOW condition
    if(q->rear == MAX_SIZE-1){
        printf("Overflow\n");
        return;
    }
    //if queue is empty
    if(q->front == -1 || q->front > q->rear){
        q->front=0;
        q->rear=0;
        q->arr[q->rear] = val;
        return;
    }
    q->rear++;
    q->arr[q->rear] = val;
}

//implementing DEQUEUE
void dequeue(struct Queue*q){
    //if queue is empty
    if(q->front == -1 || q->front > q->rear){
        printf("Underflow \n");
        return;
    }
    q->front++;
}

int peek(struct Queue*q){
    if(q->front == -1 || q->front > q->rear){
        printf("The queue is empty");
        return -1;
    }

    return q->arr[q->front];
}

bool isEmpty(struct Queue*q){
    return q->front == -1 || q->front > q->rear;
}
