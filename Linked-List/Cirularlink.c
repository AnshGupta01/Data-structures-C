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

int main(){
int ans;
    create();
    do{
    printf("\nWhat do you want to do?\n");
    printf("1. Display\n");
    printf("2. Print Length\n");
    printf("3. Insert\n");
    printf("4. Delete\n");
    printf("5. Quit\n");
    printf("Answer: ");
    scanf("%d", &ans);
    switch(ans)
    {
        case 1: display();break;
        case 2: print_len();break;
        case 3: insert();break;
        case 4: delete();break;
        case 5:break;
        default: break;
    }
    } while (ans != 5);
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
    int pos;
    int i = 1;
    printf("Where you wanna insert your node?\n");
    printf("1. First Position\n2. Middle\n3. Last Position\n");
    scanf("%d", &choice);

    switch(choice){
        case 1: newnode -> next = tail -> next;
        tail -> next = newnode;
        break;

        case 2:printf("Enter the Position you want to insert at: ");
        scanf("%d", &pos);



        case 3: newnode -> next = tail -> next;
        tail -> next = newnode;
        tail = newnode;
        break;

        default:break;    
    }
}

// Function to delete a Node from the list.
void delete(){

}
