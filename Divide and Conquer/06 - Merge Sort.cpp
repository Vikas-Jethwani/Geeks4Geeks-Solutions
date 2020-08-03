// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i=l, j=m+1, pos=0;
    vector<int> brr(r-l+1);
    while (i<=m && j<=r)
    {
        if (arr[i] <= arr[j])
            brr[pos++] = arr[i++];
        else
            brr[pos++] = arr[j++];
    }
    while (i <= m)
        brr[pos++] = arr[i++];
    while (j <= r)
        brr[pos++] = arr[j++];

    for (i=0; i<brr.size(); i++)
        arr[l+i] = brr[i];
}
