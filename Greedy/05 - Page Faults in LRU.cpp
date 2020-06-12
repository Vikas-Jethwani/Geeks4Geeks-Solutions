/*
    Per operation cost:
        O(cap) solution.
        Using sets and maps can be reduced to O(cap + log(cap)).
        Using doubly linked list and maps can be reduced to O(1).
*/
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
        int n, c;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++)
            cin>>arr[i];
        cin>>c;

        vector <int> lru;
        int faults=0;
        for (int i=0; i<n; i++)
        {
            bool found = false;
            for (int j=0; j<lru.size(); j++)
            {
                if (arr[i] == lru[j])
                {
                    lru.erase(lru.begin() + j);
                    lru.push_back(arr[i]);
                    found = true;
                    break;
                }
            }

            if (found)
                continue;
            else
                faults++;
    
            if (lru.size() == c)
                lru.erase(lru.begin());

            lru.push_back(arr[i]);
        }

        cout<<faults<<endl;
    }
    return 0 ;
}
