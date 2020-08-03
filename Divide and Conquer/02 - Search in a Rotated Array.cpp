// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int BS(int arr[], int n, int k)
{
    int low=0, high=n-1, mid;
    while (low <= high)
    {
        mid = (low+high)/2;
        if (arr[mid] == k)
            return mid;

        if (arr[mid] < arr[high]) // Right side pe sabb sahi hai, increasing sequence
        {
            if (arr[mid] < k && k <= arr[high]) // element in right half
                low = mid+1;
            else
                high = mid-1;
        }
        else // Left side pe sabb sahi hai, increasing sequence
        {
            if (arr[low] <= k && k < arr[mid]) // element in left half
                high = mid-1;
            else
                low = mid+1;
        }
    }
    return -1;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++)
            cin>>arr[i];
        cin>>k;

        cout<< BS(arr, n, k) <<endl;
    }
    return 0;
}
