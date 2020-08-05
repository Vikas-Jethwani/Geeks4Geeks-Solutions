// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

/* Main function to do heap sort.
This function uses buildHeap() and heapify().
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
*/

// The functions should be written in a way that array become sorted
// in increasing order when above heapSort() is called. [MAX HEAP]
// To heapify a subtree rooted with node i which is an index in arr[].
// n is size of heap. This function is used in above heapSort()
void heapify(int arr[], int n, int i) 
{
    while (i < n)
    {
        int left = 2*i+1;
        int right = left + 1;

        // Termination Conditions
        if (left >= n) // left and right, both out of range
            break;
        if (right == n) // left node is in range
        {
            if (arr[i] < arr[left])
                swap(arr[i], arr[left]);
            break;
        }
        if (arr[i] > arr[left] && arr[i] > arr[right]) // node reached its correct position
            break;

        // Swapping cases
        if (arr[left] > arr[right])
        {
            swap(arr[i], arr[left]);
            i = left;
        }
        else
        {
            swap(arr[i], arr[right]);
            i = right;
        }
    }
}

// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)
{
    for (int i=n-1; i>=0; i--)
        heapify(arr, n, i);
}
