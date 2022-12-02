#define N 5
#include<stdio.h>
#include<stdlib.h>
int s1[N], s2[N];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int data){
    if(top1 == N -1){
        printf("Overflow condition");
    }
    else{
        top1++;
        s1[top1] = data;
    }
}

int pop1(){
    return s1[top1--];
}
int pop2(){
    return s2[top2--];
}

void push2(int data){
    if(top2 == N -1){
        printf("Overflow condition");
    }
    else{
        top2++;
        s2[top2] = data;
    }
}

void enqueue(int x){
    push1(x);
    count++;
}

void dequeue(){ 
    if(top1 == -1 && top2 == -1){
        printf("The queue is empty");
    }
    else{
        for(int i = 0; i<count; i++){
            push2(pop1());
        }
        int a = pop2();
        printf("The DeQueued element is [%d], a");
        count--;
        for (int i = 0; i < count; i++){
            push1(pop2());
        }
    }
}

void display(){
    printf("Your queue is: ");
    for(int i = 0; i <= top1; i++){
        printf("[%d]->", s1[i]);
    }
}