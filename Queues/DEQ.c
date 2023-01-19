#define N 5
#include<stdlib.h>
#include<stdio.h>
int DEQ[N];
int Front = -1, Rear = -1;

void enqueuefront(int data){
    if( (Front == Rear -1) || (Front==0 && Rear == N-1) )
    {
        printf("The queue is full");
    }
    else if(Front == -1 && Rear == -1){
        Front=Rear=0;
        DEQ[Front] = data;
    }
    else if (Front ==0){
        Front = N-1;
        DEQ[Front] = data;
    }
    else{
        Front--;
        DEQ[Front ]=data;
    }
}

void enqueuerear(int data){
    if( (Front == Rear -1) || (Front==0 && Rear == N-1) )
    {
        printf("The queue is full");
    }
    else if(Front == -1 && Rear == -1){
        Front=Rear=0;
        DEQ[Rear] = data;
    }
    else if(Rear == N-1){
        Rear = 0;
        DEQ[Rear] = data;
    }
    else{
        Rear++;
        DEQ[Rear] = data;
    }
}

void display(){
    printf("Your queue is: ");
    int i = Front;
    while(i != Rear){
        printf("[%d]", DEQ[i]);
        i = (i+1)%N;
    }
    printf("[%d]", DEQ[Rear]);
}

void getfront(){
    printf("[%d]", DEQ[Front]);
}

void getrear(){
    printf("[%d]", DEQ[Rear]);
}

void dequeuefront(){
    if(Front == -1 && Rear == -1){
        printf("The Queue is empty");
    }
    else if(Front == Rear){
        printf("[%d]", DEQ[Front]);
        Front = Rear = -1;
    }
    else if(Front == N-1){
        printf("[%d]", DEQ[Front]);
        Front = 0;
    }
    else{
        printf("[%d]", DEQ[Front]);
        Front++;
    }
}

void dequeuerear(){
    if(Front == -1 && Rear == -1){
        printf("The Queue is empty");
    }
    else if(Front == Rear){
        printf("[%d]", DEQ[Rear]);
        Front = Rear = -1;
    }
    else if (Rear == 0){
        printf("[%d]", DEQ[Rear]);
        Rear = N-1;
    }
    else{
        printf("[%d]", DEQ[Rear]);
        Rear--;
    }
}