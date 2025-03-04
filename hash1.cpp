#include <iostream>
#include <cstdlib>
#define TABLE_SIZE 10

using namespace std;

int h[TABLE_SIZE] = {0};

void insert()
{
    int key, index, i, hkey;
    cout << "\nEnter a value to insert into the hash table: ";
    cin >> key;
    hkey = key % TABLE_SIZE;
    
    for (i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey + i * i) % TABLE_SIZE;
        
        if (h[index] == 0)
        {
            h[index] = key;
            return;
        }
    }
    
    cout << "\nElement cannot be inserted\n";
}

void search()
{
    int key, index, i, hkey;
    cout << "\nEnter search element: ";
    cin >> key;
    hkey = key % TABLE_SIZE;
    
    for (i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey + i * i) % TABLE_SIZE;
        if (h[index] == key)
        {
            cout << "Value is found at index " << index << endl;
            return;
        }
        if (h[index] == 0)
            break;
    }
    
    cout << "\nValue is not found\n";
}

void display()
{
    cout << "\nElements in the hash table are:\n";
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cout << "At index " << i << "\t value = " << h[i] << endl;
    }
}

int main()
{
    int opt;
    while (true)
    {
        cout << "\nPress 1. Insert\t 2. Display \t3. Search \t4. Exit\n";
        cin >> opt;
        switch (opt)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid option! Try again." << endl;
        }
    }
    return 0;
}
