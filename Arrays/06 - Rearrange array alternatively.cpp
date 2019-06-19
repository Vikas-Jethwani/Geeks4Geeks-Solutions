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

        int start=0, end=n-1, turn=1;
        while(start <= end)
        {
            if(turn==0)
            {
                cout<<arr[start]<<" ";
                start++;
            }
            else
            {
                cout<<arr[end]<<" ";
                end--;
            }
            turn = 1 - turn;
        }
        cout<<endl;
    }
	return 0;
}