#include<stdio.h>
#include<stdlib.h>
#define N 5
int stack[N];
int top = -1;
int choice;

void PUSH();
void POP();
void PEEK();
void DISPLAY();

int main(){
    do{
    printf("\nWhat do you wanna do?: ");
    printf("\n1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. QUIT\n-->");
    scanf("%d", &choice);
    switch(choice){
        case 1: PUSH();break;
        case 2: POP();break;
        case 3: PEEK();break;
        case 4: DISPLAY();break;
        case 5: break;
        default: printf("INVALID CHOICE\n");break;
    }
    }while (choice != 5);
    return 0;
}

void PUSH(){
    int data_user;
    printf("Enter Required Data: ");
    scanf("%d", &data_user);
    if(top == N - 1){
        printf("Overflow Condition, you cannot insert");
    }
    else{
        top++;
        stack[top] = data_user;
    }
}

void POP(){
    int popped;
    if(top == -1){
        printf("Underflow condition, cant progress");
    }
    else{
        popped = stack[top];
        top--;
        printf("Popped item is [%d]", popped);
    }
}

void PEEK(){
    if (top == -1){
        printf("The stack is empty");
    }
    else{
        printf("The item is [%d]", stack[top]);
    }
}

void DISPLAY(){
    int i;
    for (i=top; i>=0; i--){
        printf("[%d]->", stack[i]);
    }
}