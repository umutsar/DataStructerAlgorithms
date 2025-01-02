#include <iostream>
using namespace std;

const int MAX_CAPACITY = 100;
int heap[MAX_CAPACITY + 1];
int real_size = 0;

void percolateUp(int index) {
    int parent = index / 2;
    int temp = heap[index];
    while (index > 1 && temp < heap[parent]) {
        heap[index] = heap[parent];
        index = parent;
        parent = parent / 2;
    }
    heap[index] = temp;
}

void percolateDown(int index) {
    int child;
    int temp = heap[index];
    while (index * 2 <= real_size) {
        child = index * 2;
        if (child != real_size && heap[child + 1] < heap[child]) {
            child++;
        }
        if (heap[child] < temp) {
            heap[index] = heap[child];
        } else {
            break;
        }
        index = child;
    }
    heap[index] = temp;
} 

void insert(int value) {
    if (real_size == MAX_CAPACITY) {
        cout << "Heap is full!" << endl;
        return;
    }
    heap[++real_size] = value;
    percolateUp(real_size);
}

int findKthLargest(int k) {
    if (k > real_size) {
        cout << "k is larger than the number of elements in the heap." << endl;
        return -1;
    }

    int tempHeap[MAX_CAPACITY + 1];
    int tempSize = 0;

    for (int i = 1; i <= real_size; i++) {
        if (tempSize < k) {
            tempHeap[++tempSize] = heap[i];
            int index = tempSize;
            int parent = index / 2;
            while (index > 1 && tempHeap[index] < tempHeap[parent]) {
                swap(tempHeap[index], tempHeap[parent]);
                index = parent;
                parent = index / 2;
            }
        } 
        else if (heap[i] > tempHeap[1]) {
            tempHeap[1] = heap[i];
            int index = 1;
            while (index * 2 <= tempSize) {
                int child = index * 2;
                if (child != tempSize && tempHeap[child + 1] < tempHeap[child]) {
                    child++;
                }
                if (tempHeap[child] < tempHeap[index]) {
                    swap(tempHeap[child], tempHeap[index]);
                } else {
                    break;
                }
                index = child;
            }
        }
    }
    return tempHeap[1];
}

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insert(value);
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int result = findKthLargest(k);
    if (result != -1) {
        cout << "The " << k << "th largest element is: " << result << endl;
    }

    return 0;
}
