// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

const int MAX = 105;
int mat[MAX][MAX];
bool visited[MAX][MAX];
int time_rot[MAX][MAX];

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        queue <pair<pair<int, int>, int> > q; // {{x, y}, tim}
        int ans = 0;

        int r, c;
        cin>>r>>c;
        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                cin>>mat[i][j];
                visited[i][j] = false;
                if (mat[i][j] == 2)
                {
                    time_rot[i][j] = 0;
                    q.push( {{i,j}, 0} );
                }
                else
                    time_rot[i][j] = INT_MAX;
            }
        }

        while (!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int tim = q.front().second;
            q.pop();

            if (x<0 || y<0 || x>=r || y>=c || visited[x][y] || mat[x][y]==0)
                continue;
            visited[x][y] = true;
            time_rot[x][y] = tim;

            q.push( {{x+1, y}, tim+1} );
            q.push( {{x-1, y}, tim+1} );
            q.push( {{x, y+1}, tim+1} );
            q.push( {{x, y-1}, tim+1} );
        }

        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                if (time_rot[i][j] == INT_MAX && mat[i][j] == 1)
                {
                    ans = -1;
                    break;
                }
                if (time_rot[i][j] != INT_MAX)
                    ans = max(ans, time_rot[i][j]);
            }
            if (ans == -1)
                break;
        }

        cout<<ans<<endl;
    }
    return 0;
}
