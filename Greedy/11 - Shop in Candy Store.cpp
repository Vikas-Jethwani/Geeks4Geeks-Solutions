/*
    end : opposite side se kitne buy krr liye hain.
    so, initially outside array: end=n.
    and loop till i can buy: start<end
*/
// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
            cin>>arr[i];

        sort(arr, arr+n);
        int start=0, end=n, min_price=0;
        while (start < end)
        {
            min_price += arr[start];
            start++;
            end -= k;
        }

        // reverse(arr, arr+n);
        start=n-1, end=-1;
        int max_price=0;
        while (start > end)
        {
            max_price += arr[start];
            start--;
            end += k;
        }
        
        cout<<min_price<<" "<<max_price<<endl;
    }
    return 0 ;
}
