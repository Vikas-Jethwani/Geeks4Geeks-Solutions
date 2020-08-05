// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

/*The structure of the class is
struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
    int parent(int i);
    int left(int i);
    int right(int i);
};
*/

/* Removes min element from min heap and returns it */
int MinHeap::extractMin()
{
    if (heap_size == 0)
        return -1;
    swap(harr[0], harr[heap_size-1]);
    heap_size--;
    MinHeapify(0); // top-to-bottom
    return harr[heap_size];
}

/* Removes element from position x in the min heap */
void MinHeap::deleteKey(int i)
{
    if (i >= heap_size)
        return;
    swap(harr[i], harr[heap_size-1]);
    heap_size--;
    MinHeapify(i);
    decreaseKey(i, harr[i]);
    // ^we might be in right subtree of root and last swap may have come from left subtree of root
    // so it can go in either direction (top or bottom)
}

/* Inserts an element at position x into the min heap */
void MinHeap::insertKey(int k)
{
    decreaseKey(heap_size, k);
    heap_size++;
}

// From ith to root (top)
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// From ith to leaves (bottom)
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}
