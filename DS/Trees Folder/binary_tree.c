#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * left, *right;
};
struct node *create(); 

int main() {
    
    struct node * root;
    root = NULL;
    root = create();
    return 0;
}

struct node *create()
{
    int x;
    char choice ='y';
    struct node * newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    
    printf("Enter the Value: ");
    scanf ("%d", &x);
    printf("\n");
    if (choice =='n')
    {
        return 0;
    }
    else
    {
        newnode->data=x;
        printf ("Do You Want To Continue? (Press y or n):");
        scanf(" %c", &choice);
    }
    if (choice != 'y' && choice != 'n')
    {
        printf("Wrong Choice\nEnter Again (y or n Only): ");
        scanf(" %c", &choice);
    }
    else if (choice =='n')
    {
        return 0;
    }
    else if (choice =='y')
    {
        printf("Enter the Value of Left Child\n");
        newnode->left = create();
        printf("Enter the Value of Right Child\n");
        newnode->right = create();

    return newnode;
    }
} 