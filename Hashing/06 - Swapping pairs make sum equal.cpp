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

        vector<int> B(m);
        unordered_map <int, bool> exists;
        int sum_a = 0, sum_b = 0;
        for (int temp, i=0; i<n; i++)
        {
            cin>>temp;
            exists[temp] = true;
            sum_a += temp;
        }
        for (int i=0; i<m; i++)
        {
            cin>>B[i];
            sum_b += B[i];
        }

        bool found = false;
        for (int i=0; i<m; i++)
        {
            int diff = sum_a + B[i] - (sum_b - B[i]);
            diff /= 2;
            if (exists[diff])
            {
                found = true;
                break;
            }
        }

        if (found)
            cout<<1<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
