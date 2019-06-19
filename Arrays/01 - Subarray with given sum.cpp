#include<bits/stdc++.h>
//Stan
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, sum;
        cin>>n>>sum;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        bool flag=false;
        int curr=arr[0];
        int ff=0, ss=0; // Index of 2 pointers

        while(ss < n)
        {
            if(curr < sum)
            {
                ss++;
                curr += arr[ss];
            }
            else if(curr > sum)
            {
                curr -= arr[ff];
                ff++;
            }
            else
            {
                flag = true;
                break;
            }
        }


        if(flag)
            cout<<ff+1<<" "<<ss+1<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}