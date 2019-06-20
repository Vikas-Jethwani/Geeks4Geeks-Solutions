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
        
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        int right_max=0;
        stack <int> leaders;
        for(int i=n-1; i>=0; i--)
        {
            if(arr[i] >= right_max)
            {
                leaders.push(arr[i]);
                right_max = arr[i];
            }
        }

        while(!leaders.empty())
        {
            cout<<leaders.top()<<" ";
            leaders.pop();
        }
        cout<<endl;
    }
    return 0;
}