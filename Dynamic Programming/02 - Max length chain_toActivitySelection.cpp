/*
    O(nlogn) by converting given problem to:
        Activity Selection (Greedy Approach)
*/
// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

/*
    struct val
    {
        int first;
        int second;
    };
*/
bool myComp(const val &p1, const val &p2)
{
    if(p1.second < p2.second)
        return true;
    else if(p1.second > p2.second)
        return false;
    else
        return p1.first < p1.second;
}

int maxChainLen(struct val p[], int n)
{
    // Sort based on 2nd value
    sort(p, p+n, myComp);

    // Greedy Approach, same as activity selection
    int ans=0, curr_mx=-1;
    for(int i=0; i<n; i++)
    {
        if(p[i].first > curr_mx)
        {
            curr_mx = p[i].second;
            ans++;
        }
    }

    return ans;
}