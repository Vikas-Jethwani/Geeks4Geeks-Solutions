/*
    Valid for kth element of N-sorted lists.
    O(logn*logm)
*/
// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int find_k(vector<int>& arr, vector<int>& brr, int start1, int end1, int start2, int end2, int k)
{
    if (start1 > end1) // arr is over
        return brr[start2+k-1];
    if (start2 > end2) // brr is over
        return arr[start1+k-1];
    if (k == 1)
        return min(arr[start1], brr[start2]);

    int m1 = (start1 + end1)/2;
    int m2 = lower_bound (brr.begin()+start2, brr.end(), arr[m1]) - brr.begin() - 1; // -1 for elements < arr[m1]

    int left = m1-start1+1 + m2-start2+1; // including the mid elements
    if (k == left)
        return arr[m1];
    else if (k > left)
        return find_k(arr, brr, m1+1, end1, m2+1, end2, k-left);
    else
        return find_k(arr, brr, start1, m1-1, start2, m2, k);
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, m, k;
        cin>>n>>m>>k;
        vector<int> arr(n), brr(m);
        for (int i=0; i<n; i++)
            cin>>arr[i];
        for (int i=0; i<m; i++)
            cin>>brr[i];

        cout<< find_k(arr, brr, 0, n-1, 0, m-1, k) <<endl;
    }
    return 0;
}
