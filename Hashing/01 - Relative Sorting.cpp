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
        int n, m;
        cin>>n>>m;
        vector<int> A1(n), left_out;
        unordered_map<int, int> freq;
        unordered_map<int, bool> A2;
        for (int i=0; i<n; i++)
        {
            cin>>A1[i];
            freq[A1[i]]++;
        }
        for (int temp, i=0; i<m; i++)
        {
            cin>>temp;
            A2[temp] = true;
            while (freq[temp] > 0)
            {
                cout<<temp<<" ";
                freq[temp]--;
            }
        }

        for (int i=0; i<n; i++)
        {
            if (A2[A1[i]])
                continue;
            else
                left_out.push_back(A1[i]);
        }
        sort(left_out.begin(), left_out.end());

        for (int i=0; i<left_out.size(); i++)
            cout<< left_out[i] <<" ";
        cout<<endl;
    }
    return 0;
}
