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

        int curr_max=0, max_all=-1e9;

        for(int i=0; i<n; i++)
        {
            curr_max += arr[i];

            // Dont put below updating curr_max=0 line
            // else wont work when input has all neg no.
            max_all = max(max_all, curr_max);

            if(curr_max < 0)
                curr_max = 0;
        }
        
        cout<<max_all<<endl;
    }
    return 0;
}