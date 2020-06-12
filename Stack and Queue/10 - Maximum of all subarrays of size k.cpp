// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

vector<int> max_in_sliding_window(int n, vector<int> arr, int k)
{
    deque<int> dq; // Stores indices; or could've done a pair<value, index>
    for (int i=0; i<k; i++) // k<n
    {
        if (dq.empty())
            dq.push_back(i);
        else
        {
            while (!dq.empty() && arr[i] >= arr[dq.back()]) // both '>=' and '>' will w ork
                dq.pop_back();

            dq.push_back(i);
        }
    }

    vector<int> ans;
    int start=0, end=k-1;
    while (end < n)
    {
        ans.push_back(arr[dq.front()]);
        start++;
        end++;

        // If front is not part of window anymore.
        if (dq.front() < start)
            dq.pop_front();

        // Right end of window check with deque
        if (dq.empty())
            dq.push_back(end);
        else
        {
            while (!dq.empty() && arr[end] >= arr[dq.back()]) // check >= or >
                dq.pop_back();

            dq.push_back(end);
        }
    }
    return ans;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for (int i=0; i<n; i++)
            cin>>arr[i];

        vector<int> ans = max_in_sliding_window(n, arr, k);

        for (int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
