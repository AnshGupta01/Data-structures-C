#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

// enqueue  is the same as circular linked list creation.
// dequeue is also same, the front node is deleted and the rest links are updated.
// peek will display data at front node pointer

void display(){
    struct node *temp;
    temp = front;
    if (front == NULL && rear == NULL){
        printf("The list is empty");
    }
    else{
        while (temp -> next != front){
            printf("[%d]->", temp->data);
            temp = temp->next;
        }
        printf("[%d]", temp->data);
    }
}

