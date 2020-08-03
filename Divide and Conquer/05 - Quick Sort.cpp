/* This function takes last element as pivot, places  the pivot element 
   at its correct position in sorted  array, and places all smaller (smaller
   than pivot) to left of pivot and all greater elements to right  of pivot
*/
// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int j=low;
    for (int i=low; i<high; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    swap(arr[j], arr[high]);
    return j;
}
