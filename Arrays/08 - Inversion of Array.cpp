/*
    Inversion count using Merge Algorithm.
    Thanks Reddy Sir.
*/
#include<bits/stdc++.h>
//Stan
using namespace std;

long long inversions;

void merge(int A[], int l1, int r1, int l2, int r2)
{
    int p1=l1, q1=r1, p2=l2, q2=r2;
    int B[r2-l1+1], k=0;

    while(p1 <= q1 && p2 <= q2)
    {
        if(A[p1] <= A[p2])
        {
            B[k++] = A[p1++];
        }
        else
        {
            inversions += q1-p1+1;
            B[k++] = A[p2++];
        }
    }
    while(p1 <= q1)
        B[k++] = A[p1++];
    while(p2 <= q2)
        B[k++] = A[p2++];

    for(int i=0; i<k; i++)
    {
        A[l1+i] = B[i];
    }
}

void mergesort(int A[], int l, int r)
{
    if(l != r)
    {
        int mid = (l+r)/2;
        mergesort(A, l, mid);
        mergesort(A, mid+1, r);
        merge(A, l, mid, mid+1, r);
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;

        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        inversions = 0;
        mergesort(arr, 0, n-1);

        cout<<inversions<<endl;
    }
    return 0;
}