#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;    
};
struct node *head, *newnode, *temp;

void create();
void display();

int main(){
    int ans;
    create();
    do{
    printf("\nWhat do you want to do?\n");
    printf("Press 1 to display\n");
    printf("Press 2 to Quit\n");
    printf("Answer: ");
    scanf("%d", &ans);
    switch(ans)
    {
        case 1: display();break;
        case 2: break;
        default: break;
    }
    } while (ans != 2);

    return 0;
}

void create()
{
    head =0;
    int choice = 1;
    do{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data for the first node: ");
    scanf("%d", &newnode -> data);
    newnode -> prev = 0;
    newnode -> next = 0;
    if(head ==0)
        {
            head = temp = newnode;
        }
    else
        {
            temp -> next = newnode;
            newnode -> prev = temp;
            temp = newnode;
        }
    printf("Do you want to continue? (0 or 1): ");
    scanf("%d", &choice);
    } 
    while (choice != 0);
}

void display(){
    temp = head;
    while (temp != 0){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
}
