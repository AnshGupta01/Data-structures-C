#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enQueue(int x){
    if (rear == N-1){
        printf("Queue Overflow");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else{
        rear++;
        queue[rear] = x;
    }
}

void deQueue(){
    if (front == -1 && rear == -1){
        printf("Underflow Condition");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        front++;
    }
}

void display(){
    if ( front == -1 && rear == -1){
        printf("List is empty");
    }
    else{
        for(int i = front; i< rear+1;i++){
            Printf("[%d]-->", queue[i]);
        }
    }
}

void peek(){
    if (front == -1 && rear == -1){
        printf("Underflow Condition");
    }
    else{
        printf("The Peeked Value is - [%d]", queue[front]);
    }
}