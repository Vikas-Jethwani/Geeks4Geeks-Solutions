/*
    Stupid ques statement.
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
        vector<int> arr(n);
        unordered_map<int, int> freq;
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
            freq[arr[i]]++;
        }

        bool found = false;
        for (int i=0; i<n; i++)
        {
            if (freq[arr[i]] == k)
            {
                cout<<arr[i]<<endl;
                found = true;
                break;
            }
        }
        if (found == false)
            cout<<-1<<endl;
    }
    return 0;
}
