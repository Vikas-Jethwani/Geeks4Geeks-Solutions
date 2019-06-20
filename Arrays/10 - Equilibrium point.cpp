#include<bits/stdc++.h>
//Stan
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;

        // left has sum upto that position(excluding that position)
        int arr[n], left[n], right[n];
        left[0] = 0;
        right[n-1] = 0;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            if(i > 0)
            {
                left[i] = left[i-1] + arr[i-1];
            }
        }

        // set right array
        for(int i=n-2; i>=0; i--)
        {
            right[i] = right[i+1] + arr[i+1];
        }

        int pos = -1;
        for(int i=0; i<n; i++)
        {
            if(left[i] == right[i])
            {
                pos = i+1; // 0-based index
                break;
            }
        }

        cout<<pos<<endl;
    }
    return 0;
}