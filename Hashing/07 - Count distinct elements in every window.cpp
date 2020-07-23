// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

vector <int> countDistinct (int A[], int n, int k)
{
    vector<int> ans;
    int curr=0;
    unordered_map<int, int> freq;
    // Add first k elements to window
    for (int i=0; i<min(k, n); i++)
    {
        if (freq[A[i]] == 0)
            curr++;
        freq[A[i]]++;
    }
    ans.push_back(curr);
    for (int j=0, i=k; i<n; j++, i++)
    {
        // Add element from window
        if (freq[A[i]] == 0)
            curr++;
        freq[A[i]]++;
        // Remove element from window
        if (freq[A[j]] == 1)
            curr--;
        freq[A[j]]--;

        ans.push_back(curr);
    }
    return ans;
}
