#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;

void PUSH(int x){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = top;
    top = newnode;
}

void DISPLAY(){
    struct node *temp = top;
    if (top == NULL){
        printf("The stack is empty");
    }
    else{
        while(temp != NULL){
            printf("[%d]-->", temp -> data);
            temp = temp -> next;
        }
    }
}

void PEEK(){
    if(top == NULL){
        printf("The stack is empty");
    }
    else{
        printf("The top element is [%d]", top -> data);
    }
}

void POP(){
    struct node *temp = top;
    if (top == NULL){
        printf("The stack is empty");
    }
    else{
        printf("The popped element is [%d]", top -> data);
    }
    top = top -> next;
    free(temp); 
}

void main(){
    int choice, val;
    do{
    printf("\nWhat do you wanna do?: ");
    printf("\n1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. QUIT\n-->");
    scanf("%d", &choice);
    switch(choice){
        case 1:printf("What value do you wanna PUSH?: ");
            scanf("%d", &val);
            PUSH(val); break;
        case 2: POP(); break;
        case 3: PEEK(); break;
        case 4: DISPLAY(); break;
        case 5: break;
        default: printf("INVALID CHOICE\n");break;
    }
    }while (choice != 5);
}
