#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;


void enqueue(int x){
    if (front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else if (((rear+1)%N) == front){
        printf("Queue is full");
    }
    else{
        rear = (rear + 1)%N;
        queue[rear] = x;
    }
}
void dequeue(){
    if (front == NULL && rear == NULL){
        printf("Queue is empty");
    }
    else if (front == rear){
        printf("element is [%d]", queue[front]);
        front = rear = -1;
    }
    else{
        printf("element is [%d]", queue[front]);
        front = (front + 1)%N;
    }
}

void display(){
    printf("The queue is: ");
    int i = front;
    while(i != rear){
        printf("[%d]->", queue[i]);
        i = (i + 1)%N;
    }
}

void peek(){
    if (front == -1 && rear == -1){
        printf("The queue is empty");
    }
    else{
        printf("Top element is -[%d]", queue[front]);
    }
}
