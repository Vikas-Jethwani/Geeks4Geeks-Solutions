/*
    stack with indices too.
    if arr[i] <= s.top:
        wait for next greater element
    else:
        this new element is next larger element for stack ke top elements
        until arr[i] > s.top
*/
// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        cin>>n;
        long long arr[n];
        long long ans[n];
        stack < pair<long long, int> > s; // value, index

        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
            if (!s.empty())
            {
                long long val = s.top().first;
                int idx = s.top().second;
                if (arr[i] <= val) // New element less than top of stack
                {
                    s.push({arr[i], i});
                }
                else
                {
                    while (arr[i] > val) // Until the new value is the greater than stack top
                    {
                        ans[idx] = arr[i]; // Next element for that index is current input

                        s.pop();
                        if (s.empty())
                            break;
                        val = s.top().first;
                        idx = s.top().second;
                    }
                    s.push({arr[i], i});
                }
            }
            else
            {
                s.push({arr[i], i});
            }
        }
        // Elements left in stack do not have next_larger_element
        while (!s.empty())
        {
            long long val = s.top().first;
            int idx = s.top().second;
            s.pop();
            ans[idx] = -1;
        }

        for (int i=0; i<n; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
