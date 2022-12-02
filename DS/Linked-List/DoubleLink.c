// Created on Saturday 15th October 2022
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;    
};
struct node *head, *newnode, *temp, *tail, *nextnode, *currentnode;
int len = 0;

void create();
void display();
int get_len();
void print_len();
void insert_beg();
void insert_end();
void insert_at_pos();
void delete_beg();
void delete_end();
void delete_at_pos();
void reverse_list();

//  Main function
int main(){
    int ans;
    create();
    do{
    printf("\nWhat do you want to do?\n");
    printf("1. Display\n");
    printf("2. Print Length\n");
    printf("3. Insert at beginning\n");
    printf("4. Insert at end\n");
    printf("5. Insert at desired location\n");
    printf("6. Delete from beginning\n");
    printf("7. Delete from End\n");
    printf("8. Delete from Desired Position\n");
    printf("9. Reverse the linked list\n");
    printf("10. Quit\n");
    printf("Answer: ");
    scanf("%d", &ans);
    switch(ans)
    {
        case 1: display();break;
        case 2: print_len();break;
        case 3: insert_beg();break;
        case 4: insert_end();break;
        case 5: insert_at_pos();break;
        case 6: delete_beg();break;
        case 7: delete_end();break;
        case 8: delete_at_pos();break;
        case 9: reverse_list();break;
        case 10:break;
        default: break;
    }
    } while (ans != 10);
    return 0;
}

// Function to create the doubly linked list
void create()
{
    head =0;
    int choice = 1;
    do{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data for the node: ");
    scanf("%d", &newnode -> data);
    newnode -> prev = 0;
    newnode -> next = 0;
    if(head ==0)
        {
            head = tail = newnode;
        }
    else
        {
            tail -> next = newnode;
            newnode -> prev = tail;
            tail = newnode;
        }
    printf("Do you want to continue? (0 or 1): ");
    scanf("%d", &choice);
    } 
    while (choice != 0);
    display();
}

// Function to display the linked list
void display(){
    temp = head;
    while (temp != 0){
        printf("%d-->", temp -> data);
        temp = temp -> next;
    }
}

// Function to get length of the linked list
int get_len(){
    temp = head;
    while(temp != 0){
        temp = temp -> next;
        len++;   
    }
    return len;
}

// function to print the length of the linked list
void print_len(){
    printf("The number of nodes in the linked list is/are: %d", get_len());
}

// Function to insert a node at the beginning
void insert_beg(){
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> next = 0;
    newnode -> prev = 0;
    printf("Enter data for the node: ");
    scanf("%d", &newnode -> data);

    head -> prev = newnode;
    newnode -> next = head;
    head = newnode;
}

// Function to insert a node at the end
void insert_end(){
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> next = 0;
    newnode -> prev = 0;
    printf("Enter data for the node: ");
    scanf("%d", &newnode -> data);

    tail -> next = newnode;
    newnode -> prev = tail;
    tail = newnode;
}

// Function to insert at a desired position
void insert_at_pos(){
    temp = head;
    int pos = 1;
    int i = 1;
    printf("At which position do you want to add the data?: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > get_len()){
        printf("Invalid entry");
    }
    else if(pos == 1){
        insert_beg();
    }
    else
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode -> next = 0;
        newnode -> prev = 0;
        printf("Enter data for the node: ");
        scanf("%d", &newnode -> data);
        
        while(i < pos - 1)
        {
            temp = temp -> next;
            i++;
        }
        nextnode = temp -> next;
        newnode -> prev = temp;
        newnode -> next = nextnode;
        temp -> next = newnode;
        nextnode -> prev = newnode;
    }
}

// Function to delete from beginning
void delete_beg(){
    temp = head;
    if (head == 0){
        printf("The list is empty");
    }
    else{
        head = head -> next;
        head -> prev = 0;
        free(temp);
    }
}

// Function to delete from end
void delete_end(){
    if (tail == 0){
        printf("Invalid List");
    }
    else{
        temp = tail;
        tail -> prev -> next = 0;
        tail = tail -> prev;
        free(temp);
    }
}

// Function to delete from a desired position
void delete_at_pos(){
    int pos;
    int i = 1;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > get_len()){
        printf("Invalid Position");
    }
    else if(pos == 1){
        delete_beg();
    }
    else if(pos == get_len()){
        delete_end();
    }
    else
    {
        temp = head;
        while(i < pos)
        {
            temp = temp -> next;
            i++;
        }
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        free(temp);
    }
}

// Function to reverse the linked list
void reverse_list(){
    currentnode = head;
    while (currentnode !=0)
    {
        nextnode = currentnode -> next;
        currentnode -> next = currentnode -> prev;
        currentnode -> prev = nextnode;
        currentnode = nextnode;
    }
    currentnode = head;
    head = tail;
    tail = currentnode;
}