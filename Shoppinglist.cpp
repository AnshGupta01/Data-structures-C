// This is a code to add shopping items with their name, prices and do operations on this data.
#include <iostream>
using namespace std;
//  trying to re clone
class items {
    public:
    int itemprice[10];
    string itemname[10];
    int count = 0;

//  FOR FETCHING ITEMS
    void getitems() 
    {
    cout << "Enter the Item price for item" << endl;
    cin >> itemprice[count];
    cout << "Enter the Item Name for item" << endl;
    cin >> itemname[count];
    count++;
    }

//  FOR SUM OF PRICES
    void sumofprices()
    {
        int sum = 0;
        for(int i=0; i<count; i++){
            sum = sum + itemprice[i];
        }
        cout << "THE VALUE OF ALL YOUR PRODUCT IS " << sum;
    }

// TO ERASE THE ITEM PRICES
    void itemremove() 
    {
        string a;
        cout << "Enter item name" << endl;
        cin >> a;

        for(int i=0; i<count; i++){
            if (itemname[i] == a) {
                itemprice[i] = 0;
            }
            
        }
    }

// TO DISPLAY ALL ITEMS
    void displayitem()
    {
        for (int i=0;i<count;i++){
            cout << itemname[i];
            cout << itemprice[i];
            
        }
    }
};
//  MAIN FUNCTION
int main() {
    items ansh;
    int bablu;
    cout << "Enter the number of items";
    cin >> bablu;
    
    for (int i = 0; i<bablu;i++)
    {
        ansh.getitems();
    }   
    
    int x;
    do {
        cout << "\nWhat do you want to do?\n";
        cout << "Press 1 to Display all items\n";
        cout << "Press 2 to Sum all prices\n";
        cout << "Press 3 to Erase an item\n";
        cout << "Press 4 to quit";
        cin >> x;
// Switch statement:
        switch(x) {
        case 1: ansh.displayitem();break;
        case 2: ansh.sumofprices();break;
        case 3: ansh.itemremove();break;
        case 4: break;
        default: cout << "Wrong input baby\n";
        }
        
    }
    while (x != 4);
    
    return 0;

}
