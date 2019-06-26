#include<bits/stdc++.h>
//Stan
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int m, n;
        cin>>m>>n;

        int mat[m][n];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
                cin>>mat[i][j];
        }

        char directions[4]={'R', 'D', 'L', 'U'};
        int dir=0, spiral=0, i=0, j=0, total=m*n, done=0;
        while(done < total)
        {
            done++;
            cout<<mat[i][j]<<" ";
            if(directions[dir] == 'R')
            {
                if(j == n-1-spiral)
                {
                    i++;
                    dir++;
                }
                else
                    j++;
            }
            else if(directions[dir] == 'D')
            {
                if(i == m-1-spiral)
                {
                    j--;
                    dir++;
                }
                else
                    i++;
            }
            else if(directions[dir] == 'L')
            {
                if(j == 0+spiral)
                {
                    i--;
                    dir++;
                    spiral++; // Spiral Arms
                }
                else
                    j--;
            }
            else if(directions[dir] == 'U')
            {
                if(i == 0+spiral)
                {
                    j++;
                    dir = 0; // Now Right Turn
                }
                else
                    i--;
            }
        }
        cout<<endl;
    }
    return 0;
}