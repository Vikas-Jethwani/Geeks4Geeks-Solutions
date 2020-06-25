// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int josephus(int n, int k)
{
    k--;
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);

    int idx=0;
    while (arr.size() != 1)
    {
        idx = (idx+k)%arr.size();
        arr.erase(arr.begin()+idx);
        idx = idx%arr.size();
    }

    return arr[0];
}
