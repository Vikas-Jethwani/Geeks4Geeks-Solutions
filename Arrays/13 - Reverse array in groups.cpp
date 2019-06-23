#include<bits/stdc++.h>
//Stan
using namespace std;

void reverse(int A[], int start, int end)
{
    while(start <= end)
    {
        swap(A[start], A[end]);
        start++;
        end--;
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, k;
        cin>>n>>k;

        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        for(int i=0; i<n; i+=k)
        {
            reverse(arr, i, min(i+k, n) - 1);
        }

        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;   
    }
    return 0;
}