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
        int n;
        cin>>n;
        unordered_map<int, int> freq1, freq2;
        for (int temp, i=0; i<n; i++)
        {
            cin>>temp;
            freq1[temp]++;
        }
        for (int temp, i=0; i<n; i++)
        {
            cin>>temp;
            freq2[temp]++;
        }

        int equal = 1;
        for (auto tr: freq1)
        {
            if (tr.second != freq2[tr.first])
            {
                equal = 0;
                break;
            }
        }

        cout<<equal<<endl;
    }
    return 0;
}
