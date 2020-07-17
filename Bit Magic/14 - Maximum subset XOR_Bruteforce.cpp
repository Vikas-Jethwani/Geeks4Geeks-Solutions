/*
    Bruteforce: O(2^n)
*/
// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

map<pair<int, int>, int> mm;

int dfs(int A[], int pos, int curr, int n)
{
    if (mm.find({pos, curr}) != mm.end())
        return mm[{pos, curr}];

    if (pos == n)
    {
        mm[{pos, curr}] = curr;
        return curr;
    }

    mm[{pos, curr}] = max(dfs(A, pos+1, curr^A[pos], n), dfs(A, pos+1, curr, n));
    return mm[{pos, curr}];
}

int maxSubarrayXOR(int A[], int n)
{
    mm.clear();
    return dfs(A, 0, 0, n);
}