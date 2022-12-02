#include <stdio.h>

void Display();
void insert();
void delete();
void search();
long int sort();

int arr[100];
int num;


int main(){
    printf("Enter your number of elements for your array: ");
    scanf("%d", &num);

    // Accepting Elements into the array
    for(int i=0;i<num;i++){ 
        printf("\nYour element [%d]:" ,i);
        scanf("%d", &arr[i]);
    }
    // Menu asking for things to do:
    int do_what;
    do
    {
        
        printf("What do you want to do?\n");
        printf("1. Display\n2. Insert\n3. Delete\n4. Search\n5. Sorting\n6. Quit");
        scanf("%d", &do_what);

        switch(do_what){
            case 1: Display();break;
            case 2: insert();break;
            case 3: delete();break;
            case 4: search();break;
            case 5: sort();break;
            case 6: break;
            default:printf("invalid value");
        } 
    } while(do_what != 6);
return 0;
}

void Display() {
    for (int i=0; i<num; i++){
        printf("Element is [%d]\n", arr[i]);
    }
}

void insert(){
    int place, elem;
    printf("At which place do you want to insert an element?\n");
    scanf("%d", &place);
    printf("What element do you want to insert?");
    scanf("%d",&elem);
    num++;

    for(int i=num-1;i>=place;i--) {
        arr[i] = arr[i-1];
    }
    arr[place-1]=elem;
    printf("Your new elements are :\n");
    Display();
}

void delete(){
    int pos;
    int temp;
    printf("At which place do you want to delete an element?\n");
    scanf("%d", &pos);

    for(int i = pos-1;i<=num-1;i++){
        arr[i] = arr[i+1];
    }
    num--;
    Display();   
}

long int sort(){
    // To sort an array:
    int temp;
    for(int i=0;i<num-1;i++)
    {
        for(int j = i+1;j<num;j++)
        {
            if(arr[i] > arr[j]) 
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    printf("Your sorted array is: \n");
    Display();
    return 0;

}

// program for binary search
void search(){
    
}
