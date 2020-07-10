// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

#define INF 1e7

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int dist[n][n];
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                cin>>dist[i][j];

        for (int k=0; k<n; k++)
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (dist[i][j] == INF)
                    cout<<"INF ";
                else
                    cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }        
    }
    return 0;
}
