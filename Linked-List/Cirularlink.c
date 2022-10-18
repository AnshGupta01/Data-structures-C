#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *newnode, *head, *temp;

void create();
void display();

main(){
    create();
    display();
}

void create(){
    head = temp = NULL;
    int num = 0;
    printf("Enter the number of Nodes you want: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++){
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for your [%d] node: ", i);
    scanf("%d", &newnode -> data);
    newnode ->next = 0;
    if (head == NULL)
        {
        head = temp = newnode;
        }
    else{
        temp ->next = newnode;
        temp = newnode;
        }
    temp ->next = head;
    printf("\n");
    }  
}

void display(){
    if (head == NULL){
        printf("The list is empty\n");
    }
    else{
        temp = head;
        while (temp ->next != head)
        {
            printf("[%d]->", temp ->data);
            temp = temp ->next;
        }
        printf("[%d]\n", temp ->data);
    }
}
