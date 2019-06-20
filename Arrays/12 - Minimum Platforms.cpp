#include<bits/stdc++.h>
//Stan
using namespace std;

bool mySort(pair<int, int> t1, pair<int, int> t2)
{
    if(t1.first < t2.first)
        return true;
    else if(t1.first > t2.first)
        return false;
    else
    {
        if(t1.second < t2.second)
            return false;
        else
            return true;
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

        int arr, dep;
        pair<int, int> timing[2*n];
        for(int i=0; i<n; i++)
        {
            cin>>arr;
            timing[i] = {arr, 1};
        }
        for(int i=0; i<n; i++)
        {
            cin>>dep;
            timing[i + n] = {dep, -1};
        }

        // mySort to put arrival before departure for safety(extra platform)
        sort(timing, timing+2*n, mySort);
        int curr_platforms=0, max_platforms=0;
        for(int i=0; i<2*n; i++)
        {
            curr_platforms += timing[i].second;
            max_platforms = max(max_platforms, curr_platforms);
        }

        cout<<max_platforms<<endl;
    }
    return 0;
}