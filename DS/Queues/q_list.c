#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode ->data = x;
    newnode -> next = NULL;
    if (front == NULL && rear == NULL){
        front = rear = newnode;
    }
    else{
        rear -> next = newnode;
        rear = newnode;
    }
}

void display(){
    struct node *temp;
    if(front == NULL && rear == NULL){
        printf("Invalid queue");
    }
    else{
        temp = front;
        while (temp != NULL){
            printf("[%d]->", temp->data);
            temp = temp -> next;
        }
    }
}

void dequeue(){
    struct node *temp;
    temp = front;
    printf("The popped out data is -[%d]-", front -> data);
    front = front -> next;
    free(temp);
}

void peek(){
    if (front == NULL && rear == NULL){
        printf("Invalid entry");
    }
    else{
        printf("The data in front is [%d]", front -> data);
    }
}
