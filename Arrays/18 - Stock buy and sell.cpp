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

        int arr[n+1];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        arr[n] = -1; // to fit in 'end' day
        queue <pair<int, int> > days;
        int start=-1, end;
        for(int i=0; i<n; i++)
        {
            if(start == -1)
            {
                if(arr[i] < arr[i+1])
                    start = i;
            }
            else
            {
                if(arr[i] > arr[i+1])
                {
                    end = i;
                    days.push({start, end});
                    start = -1;
                }
            }
        }

        if(days.empty())
        {
            cout<<"No Profit\n";
        }
        else
        {
            while(!days.empty())
            {
                cout<<"("<<days.front().first<<" "<<days.front().second<<") ";
                days.pop();
            }
            cout<<endl;
        }
    }
    return 0;
}