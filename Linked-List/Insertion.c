#include <stdio.h>
#include<stdlib.h>

void display();
void create();
void insert_beg();
void insert_end();




void create(){
    struct node
    {
        int data;
        struct node *next;
    };

    struct node *head, *newnode, *temp;
    head = 0;
    int choice = 1;

    do
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node: ");
        scanf("%d", &newnode -> data);
        newnode -> next = 0;

        if(head == 0) 
        { 
            head = temp = newnode;
        }
        else 
        {
            temp -> next = newnode;
            temp = newnode;
        }
        printf("Do you want to add more? (0 or 1): ");
        scanf("%d", &choice);
    }
    while (choice == 1);
        temp = head;
}

void display(){
    while (temp != 0)
    {
        printf("%d", temp -> data);
        temp = temp -> next;
        printf("\n");
    }
}
void insert_beg()
{
    struct node{
        int data;
        struct node *next;
    };

    struct node *head, *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the Data you want to insert: ");
    scanf("%d", &newnode -> data);
    newnode -> next = head;
    head = newnode;
}

void insert_end(){

    struct node{
        int data;
        struct node *next;
    };

    struct node *head, *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the Data you want to insert: ");
    scanf("%d", &newnode -> data);
    newnode -> next = 0;
    temp = head;


    while(temp -> next !=0){
        temp = temp -> next;
    }
    temp -> next = newnode;
}

int main()
{
    return 0;
}
