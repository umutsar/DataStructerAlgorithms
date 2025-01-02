#include <iostream>
using namespace std;

const int MAX_CAPACITY = 100;
int dizi[MAX_CAPACITY + 1];
int real_size = 0;

void percolateUp(int index) {
    int parent = index / 2;
    int temp = dizi[index];
    while (index > 1 && temp < dizi[parent]) {
        dizi[index] = dizi[parent];
        index = parent;
        parent = parent / 2;
    }
    dizi[index] = temp;
}

void percolateDown(int index) {
    int child;
    int temp = dizi[index];
    while (index * 2 <= real_size) {
        child = index * 2;
        if (child != real_size && dizi[child + 1] < dizi[child]) {
            child++;
        }
        if (dizi[child] < temp) {
            dizi[index] = dizi[child];
        } else {
            break;
        }
        index = child;
    }
    dizi[index] = temp;
}

void insert(int value) {
    if (real_size == MAX_CAPACITY) {
        cout << "Heap is full!" << endl;
        return;
    }
    dizi[++real_size] = value;
    percolateUp(real_size);
}

int findMin() {
    if (real_size == 0) {
        cout << "Heap is empty" << endl;
        return;
    }
    return dizi[1];
}

void deleteMin() {
    if (real_size == 0) {
        cout << "Heap is empty" << endl;
    }
    dizi[1] = dizi[real_size--];
    percolateDown(1);
}

void printHeap() {
    for (int i = 1; i <= real_size; i++) {
        cout << dizi[i] << " ";
    }
    cout << endl;
}

int main() {
    insert(20);
    insert(15);
    insert(30);
    insert(5);

    cout << "Heap elemanlari: ";
    printHeap();

    cout << "En kucuk eleman: " << findMin() << endl;

    deleteMin();
    cout << "Min eleman silindikten sonra heap: ";
    printHeap();
    

    return 0;
}
