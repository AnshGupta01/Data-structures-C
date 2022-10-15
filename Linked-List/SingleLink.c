#include <stdio.h>
#include<stdlib.h>

struct node
    {
        int data;
        struct node *next;
    };
struct node *head, *newnode, *temp, *prevnode, *currentnode, *nextnode;

int count = 0;
void display();
void create();
void insert_beg();
void insert_end();
void insert_at_pos();
void delete_at_beg();
void delete_at_end();
void delete_at_pos();
void get_len();
void reverse_linked();

// Main function of the program
int main()
{
    int ans;
    create();
    do{
    printf("\nWhat do you want to do?\n");
    printf("To Display - Press 1\n");
    printf("To insert in beginning - Press 2\n");
    printf("To insert in desired position - Press 3\n");
    printf("To insert in end - Press 4\n");
    printf("\n");
    printf("To Delete in Starting - Press 5\n");
    printf("To Delete in end - Press 6\n");
    printf("To Delete at Desired Position - Press 7\n");
    printf("To get length of linked list - Press 8\n");
    printf("To reverse the linked list - Press 9\n");
    printf("To Quit - Press 10\n");
    scanf("%d", &ans);
    printf("\n");
    switch(ans){
        case 1: display();break;
        case 2: insert_beg();break;
        case 3: insert_at_pos();break;
        case 4: insert_end();break;
        case 5: delete_at_beg();break;
        case 6: delete_at_end();break;
        case 7: delete_at_pos();break;
        case 8: get_len();break;
        case 9: reverse_linked();break;
        case 10: break;
        default: printf("Invalid Answer\n");
    }
    } while(ans != 9);
    return 0;
}

// Function to create the linked list
void create(){
    head = 0;
    int choice = 1;
    do{
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
}

// Function to display the linked list
void display(){
    temp = head;
    while (temp != 0)
    {
        printf("%d", temp -> data);
        temp = temp -> next;
        printf(" ");
        count++;
    }
}

// Function to insert in the beggining of the linked list
void insert_beg(){
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
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the Position you want to insert the vairable into?: ");
    scanf("%d", &pos);
    if(pos > count) {
        printf("Invalid Position");    
    }
    else
    {
        temp = head;
        int i=1;
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

// Function to delete at the start of the linked list
void delete_at_beg(){
    temp = head;
    if(head == 0)
        {
        printf("No node to delete\n");
        }
    else
        {
        head = head -> next;
        free(temp);
        }
}

// Function to delete at the end
void delete_at_end(){
    temp = head;
    struct node *second_pointer;
    while (temp ->next !=0)
    {
        second_pointer = temp;
        temp = temp -> next;
    }
    if (temp == head)
    {
        head = 0;
        free(temp);
    }
    else
    {
        second_pointer -> next = 0;
    }
    free(temp);
}

// Function to delete at a desired position
void delete_at_pos(){
    struct node *next_pointer;
    int pos; int i=1;
    temp = head;
    printf("Enter the position you want to delete the node at: ");
    scanf("%d", &pos);
    while (i< pos-1)
    {
        temp = temp -> next;
        i++;
    }
    next_pointer = temp -> next;
    temp -> next = next_pointer -> next;
    free(next_pointer);
}

// function to get length of the linked list
void get_len(){
    int len = 0;
    temp = head;
    while(temp != 0){
        temp = temp -> next;
        len++;
    }
    printf("The number of nodes in the linked list is/are: %d", len);
}

// Function to reverse the linked list
void reverse_linked(){
    prevnode = 0;
    currentnode = nextnode = head;
    while (nextnode != 0){
        nextnode = nextnode -> next;
        currentnode -> next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
}