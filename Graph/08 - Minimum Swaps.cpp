/*
    Tricky test cases:
    2
    3
    2 3 2
    4
    5 3 1 1
    ^ WA on this TC, as it assumes 1st 1 to be 0 and 2nd 1 to be 1.
*/
// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int minSwaps(int arr[], int N)
{
    // All this to convert to [0,N-1] Range. O(n)
    pair<int,int> copy[N];
    for (int i=0; i<N; i++)
        copy[i] = {arr[i], i};
    sort(copy, copy+N);

    for (int i=0; i<N; i++)
        arr[copy[i].second] = i;

    // Now real swapping starts.
    int ans=0;
    for (int i=0; i<N; i++)
    {
        while (arr[i] != i)
        {
            ans++;
            swap(arr[i], arr[arr[i]]);
        }
    }
    
    return ans;
}
