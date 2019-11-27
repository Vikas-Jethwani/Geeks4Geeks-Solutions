// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int maxToys(int cost[], int n, int k)
{
    int ans = 0 ;
    sort(cost, cost+n) ;

    for(int i=0; i<n; i++)
    {
        if(cost[i] <= k)
        {
            ans++ ;
            k -= cost[i] ;
        }
        else
            break ;
    }

    return ans ;
}


int main()
{
    int T ;
    cin>>T ;
    while(T--)
    {
        int n, k ;
        cin>>n>>k ;

        int cost[n] ;
        for(int i=0; i<n; i++)
            cin>>cost[i] ;

        cout<< maxToys(cost, n, k) <<endl ;
    }
    return 0 ;
}
