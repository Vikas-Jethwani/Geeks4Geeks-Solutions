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
        cin>>k>>n;
        vector<int> ans(n);
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int temp, i=0; i<n; i++)
        {
            cin>>temp;
            pq.push(temp);
            if (pq.size() > k)
                pq.pop();

            if (pq.size() == k)
                ans[i] = pq.top();
            else
                ans[i] = -1;
        }

        for (auto num: ans)
            cout<<num<<" ";
        cout<<endl;
    }
    return 0;
}
