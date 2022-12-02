#include <stdio.h>
#include <stdlib.h>

// Defining the structure for the nodelist
struct node{
    int data;
    struct node *next;
};
struct node *newnode, *head, *tail, *temp;
void create();
void display();
int get_len();
void print_len();
void insert();
void delete();
void rever();

int main(){
int ans;
    create();
    do{
    printf("\nWhat do you want to do?\n");
    printf("1. Display\n");
    printf("2. Print Length\n");
    printf("3. Insert\n");
    printf("4. Delete\n");
    printf("5. Reverse the list\n");
    printf("6. Quit\n");
    printf("Answer: ");
    scanf("%d", &ans);
    switch(ans)
    {
        case 1: display();break;
        case 2: print_len();break;
        case 3: insert();break;
        case 4: delete();break;
        case 5: rever();break;
        case 6:break;
        default: break;
    }
    } while (ans != 6);
    return 0;
}

// Function to create the Circular Linked List using head and temp pointer
// void create(){
//     struct node *temp;
//     head = temp = NULL;
//     int num = 0;
//     printf("Enter the number of Nodes you want: ");
//     scanf("%d", &num);

//     for (int i = 1; i <= num; i++){
//     newnode = (struct node*)malloc(sizeof(struct node));
//     printf("Enter the data for your [%d] node: ", i);
//     scanf("%d", &newnode -> data);
//     newnode ->next = 0;
//     if (head == NULL)
//         {
//         head = temp = newnode;
//         }
//     else{
//         temp ->next = newnode;
//         temp = newnode;
//         }
//     temp ->next = head;
//     printf("\n");
//     }  
// }


// // Function to Display the created list using temp
// void display(){
//     struct node *temp;
//     if (head == NULL){
//         printf("The list is empty\n");
//     }
//     else{
//         temp = head;
//         while (temp ->next != head)
//         {
//             printf("[%d]->", temp ->data);
//             temp = temp ->next;
//         }
//         printf("[%d]\n", temp ->data);
//     }
// }


// Function to create using tail pointer
void create(){
    tail = NULL;
    int num = 0;
    printf("Enter the number of Node you want: ");  
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for your [%d] node: ", i);
    scanf("%d", &newnode -> data);
    newnode -> next = NULL;
    if (tail == NULL){
        tail = newnode;
        tail -> next = newnode;
        }
    else
        {
        newnode -> next = tail -> next;
        tail -> next = newnode;
        tail = newnode;
        }   
    }
display();
}

// // Function to Display the list using the tail pointer.
void display(){
    temp = NULL;
    if(tail == NULL){
        printf("Invalid Operation\n");
    }
    else{
        temp = tail -> next;
    }
    while (temp -> next != tail -> next){
        printf("[%d]->", temp -> data);
        temp = temp -> next;
    }
    printf("[%d]->", temp -> data);
}

// To Return length of the list.
int get_len(){
    int len = 1;
    temp = tail -> next;
    while (temp != tail){
        len++;
        temp = temp -> next;
    } return len; 
}

// To actually print the length of the list
void print_len(){
    printf("\nThe Length of the Linked list is [%d]", get_len()); 
}

// Function to insert a node
void insert(){
    temp = NULL;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for your node: ");
    scanf("%d", &newnode -> data);
    int choice;
    printf("Where you wanna insert your node?\n");
    printf("1. First Position\n2. Middle\n3. Last Position\n");
    scanf("%d", &choice);
    int pos;
    int i = 1;
    switch(choice){

        case 1: newnode -> next = tail -> next;
        tail -> next = newnode;
        break;

        case 2:
        printf("Enter the Position you want to insert at: ");
        scanf("%d", &pos);
        int l = get_len();
        if (pos < 2 || pos > l){
            printf("Invalid Position, Please Continue!!");
        }
        else{
            temp = tail -> next;
            while(i < pos - 1){
                temp = temp -> next;
                i++;
            }
            newnode -> next = temp -> next;
            temp -> next = newnode;
        }
        break;

        case 3: newnode -> next = tail -> next;
        tail -> next = newnode;
        tail = newnode;
        break;

        default:break;    
    }
}

// Function to delete a Node from the list.
void delete(){
    int choice;
    int l;
    int i;
    int pos;
    temp = tail -> next;
    printf("Where do you want to delete your node from?");
    printf("\n1. Beginning\n2. Middle\n3. End\n");
    scanf("%d", &choice);

    struct node *current, *prev, *nextnode;

    switch (choice)
    {

    case 1:
        if(temp -> next == temp)
        {
            tail = NULL;
            free(temp);
        }
        else
        {
            tail -> next = temp -> next;
            free(temp);
        }
        break;

    case 2: l = get_len();
    printf("At what position to delete the node?: ");
    scanf("%d", pos);
    current = tail ->next;
    if (pos < 2 || pos > l)
    {
        printf("Invalid Pos");
    }
    else
    {
        while (i < pos - 1){
            current = current -> next;
            i++;
        }
        nextnode = current -> next;
        current -> next = nextnode -> next;
        free(nextnode);
    }
    break;

    case 3:
        current = tail -> next;
        if (current -> next == current)
        {
            tail = NULL;
            free(current);
        }
        else
        {
            while (current -> next != tail -> next)
            {
                prev = current;
                current = current -> next;
            }
            prev -> next = tail -> next;
            tail = prev;
            free (current);
        }
        break;

    default: break;
    }
}

// Function to reverse the list.
void rever(){
    struct node *current, *prev, *nextnode;
    current = tail -> next;
    nextnode = current -> next;
    while (current != tail){
        prev = current;
        current = nextnode;
        nextnode = current -> next;
        current -> next = prev;
    }
    nextnode -> next = tail;
    tail = nextnode;
}