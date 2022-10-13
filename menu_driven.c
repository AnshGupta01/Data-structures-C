#include <stdio.h>
#include<stdlib.h>

void display();
void create();
void insert_beg();
void insert_end();

int main()
{
    int ans;
    create();

    do{
    printf("What do you want to do?\n");
    printf("To Display - Press 1\n");
    printf("To insert in beginning - Press 2\n");
    printf("To insert in end - Press 3\n");
    printf("To Quit - Press 4\n");
    scanf("%d", &ans);

    switch(ans){
        case 1: display();break;
        case 2: insert_beg();break;
        case 3: insert_end();break;
        case 4: break;
        default: printf("Invalid Answer");
    }
    } while(ans != 4);
    
    return 0;
}


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

    struct node{
        int data;
        struct node *next;
    };

    struct node *temp;
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


