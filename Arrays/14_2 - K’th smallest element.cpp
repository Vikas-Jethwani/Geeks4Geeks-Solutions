/*
    Average Case : O(n)
    Worst Case : O(n^2)
    Quick-Select Algo, also called Partition Algo
    Thank you Reddy Sir!
*/
#include<bits/stdc++.h>
//Stan
using namespace std;

// Returns index of mid
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int i=start;
    for(int j=i+1; j<=end; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[start]);

    return i;
}

int quickSort(int arr[], int start, int end, int k)
{
    int mid = partition(arr, start, end);
    if(k == mid)
        return arr[k];
    else if(k < mid)
        return quickSort(arr, start, mid-1, k);
    else
        return quickSort(arr, mid+1, end, k);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, k;
        cin>>n;

        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        cin>>k;

        // 0-based index => 'k-1'
        cout<<quickSort(arr, 0, n-1, k-1)<<endl;
    }
    return 0;
}