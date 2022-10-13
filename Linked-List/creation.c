#include <stdio.h>
#include <stdlib.h>

int main()
{
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
    while (temp != 0)
    {
        printf("%d", temp -> data);
        temp = temp -> next;
        printf("\n");
    }

    return 0;
}