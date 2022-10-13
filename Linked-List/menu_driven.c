#include <stdio.h>
#include<stdlib.h>

struct node
    {
        int data;
        struct node *next;
    };
struct node *head, *newnode, *temp;

void display();
void create();
void insert_beg();
void insert_end();
void insert_at_pos();

int count = 1;

// Main function of the program
int main()
{
    int ans;
    create();

    do{
    printf("What do you want to do?\n");
    printf("To Display - Press 1\n");
    printf("To insert in beginning - Press 2\n");
    printf("To insert in desired position - Press 3\n");
    printf("To insert in end - Press 4\n");
    printf("To Quit - Press 5\n");
    scanf("%d", &ans);

    switch(ans){
        case 1: display();break;
        case 2: insert_beg();break;
        case 3: insert_at_pos();break;
        case 4: insert_end();break;
        case 5: break;
        default: printf("Invalid Answer");
    }
    } while(ans != 4);
    
    return 0;
}

// Function to create the linked list
void create(){
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

    display();
}

// Function to display the linked list
void display(){
    temp = head;
    while (temp != 0)
    {
        printf("%d", temp -> data);
        temp = temp -> next;
        printf("\n");
        count++;
    }
}

// Function to insert in the beggining of the linked list
void insert_beg()
{

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the Data you want to insert: ");
    scanf("%d", &newnode -> data);
    newnode -> next = head;
    head = newnode;
}

// Functon to insert a node in the end of the linked list
void insert_end(){

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

// Function to insert at a desired location in the linked list
void insert_at_pos(){
    int pos;
    int i=1;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter the Position you want to insert the vairable into?: ");
    scanf("%d", &pos);
    if(pos > count) {
        printf("Invalid Position");    
    }
    else
    {
        temp = head;
        while(i<pos)
        {
            temp = temp -> next;
            i++;
        }
    }

    printf("Enter your Data which you want to insert: ");
    scanf("%d", &newnode -> data);
    newnode -> next = temp -> next;
    temp -> next = newnode;

}


