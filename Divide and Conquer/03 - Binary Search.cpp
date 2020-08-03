// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int bin_search(int A[], int left, int right, int k)
{
    while (left <= right)
    {
        if (left == right)
        {
            if (A[left] == k)
                return left;
            else
                return -1;
        }
        int mid = (left+right)/2;
        if (k == A[mid])
            return mid;
        else if (k < A[mid])
            right = mid-1;
        else
            left = mid+1;
    }
    return -1;
}
